function(download_one FILE_NAME BASE_DIR URL_DIR )
	set(DEST "${BASE_DIR}/${FILE_NAME}")
	set(URL  "https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/${URL_DIR}")

	message(STATUS "Downloading file: ${FILE_NAME}")

	# если уже есть и не пустой — выходим
	if(EXISTS "${DEST}")
		file(SIZE "${DEST}" SZ)
		if(SZ GREATER 0)
			message(STATUS "File already downloaded: ${DEST}")
			return()
		endif()
	endif()

	file(MAKE_DIRECTORY "${BASE_DIR}")

	file(DOWNLOAD
		"${URL}"
		"${DEST}"
		STATUS RES
		TLS_VERIFY ON
	)

	list(GET RES 0 CODE)
	list(GET RES 1 MSG)

	if(NOT CODE EQUAL 0)
		file(REMOVE "${DEST}")
		message(FATAL_ERROR "Download failed: ${URL}\n${MSG}")
	endif()

	file(SIZE "${DEST}" SZ)
	if(SZ EQUAL 0)
		file(REMOVE "${DEST}")
		message(FATAL_ERROR "Downloaded file is empty: ${URL}")
	endif()

	message(STATUS "Download complete! File: ${DEST}")
endfunction()

function(k_to_int K_STR OUT)
	string(REPLACE "K" "" _K "${K_STR}")
	set(${OUT} ${_K} PARENT_SCOPE)
endfunction()

function(stm32_clean_build_dir)
	message(STATUS "Cleaning build directory (except CMakeCache.txt)")

	file(GLOB BUILD_FILES
		"${CMAKE_BINARY_DIR}/*"
	)

	foreach(item IN LISTS BUILD_FILES)
		get_filename_component(name "${item}" NAME)

		if(NOT name STREQUAL "CMakeCache.txt"
		AND NOT name STREQUAL "CMakeFiles")
		file(REMOVE_RECURSE "${item}")
		endif()
	endforeach()
endfunction()

# Uniform-page families (no variable-size sectors): PAGE_SIZE in bytes
set(STM32G0_PAGE_SIZE 2048)
set(STM32C0_PAGE_SIZE 2048)

# ---------------------------------------------------------------------------
# stm32_generate_flash_config(SERIES FLASH_STR DEVICE_NAME TEMPLATE OUT_FILE)
#
# Two modes, selected automatically:
#
# 1) Sector-map mode  — ${SERIES}_SECTOR_MAP is defined.
#    Looks up FLASH_KB in the map to get single-bank sector count.
#    If STM32_DUAL_BANK is ON, count is doubled.
#    Map format: FLASH_KB  SECTOR_COUNT  (flat list, 2 fields per entry)
#
# 2) Uniform-page mode — ${SERIES}_PAGE_SIZE is defined (bytes).
#    All pages are equal; count = FLASH_KB * 1024 / PAGE_SIZE.
#    Generates FLASH_CFG_SECTORS_LIST — a list of {address, size} entries
#    for use in the flash_sectors[] array inside the .h.in template.
#
# TEMPLATE — path to the downloaded .h.in file.
# ---------------------------------------------------------------------------
function(stm32_generate_flash_config SERIES FLASH_STR DEVICE_NAME TEMPLATE OUT_FILE)

    # Strip the trailing "K" from flash size strings like "128K" → "128"
    k_to_int("${FLASH_STR}" _kb)

    # Resolve the two possible data sources for this family.
    # Both are looked up by variable-variable indirection: if SERIES="STM32G0",
    # then ${STM32G0_SECTOR_MAP} and ${STM32G0_PAGE_SIZE} are read.
    set(_map     "${${SERIES}_SECTOR_MAP}")
    set(_page_sz "${${SERIES}_PAGE_SIZE}")

    # Always initialize to empty so the @FLASH_CFG_SECTORS_LIST@ placeholder
    # in the template expands to an empty string for sector-map families
    # whose templates do not use this variable.
    set(FLASH_CFG_SECTORS_LIST "")

    if(_map)
        # --- Sector-map path --------------------------------------------------
        # Used by families with heterogeneous sector sizes (F1, F2, F4, F7 …).
        # The map is a flat CMake list of pairs:  FLASH_KB  SECTOR_COUNT  …
        # e.g.  512 8  1024 12  2048 24
        # Find the index of the matching flash size entry.
        list(FIND _map "${_kb}" _idx)
        if(_idx LESS 0)
            message(FATAL_ERROR
                "stm32_generate_flash_config: no entry for ${_kb}K in ${SERIES}_SECTOR_MAP")
        endif()

        # The sector count immediately follows the flash-size entry in the list.
        math(EXPR _i1 "${_idx} + 1")
        list(GET _map ${_i1} FLASH_CFG_COUNT)

        # Dual-bank devices expose twice as many logical sectors.
        if(STM32_DUAL_BANK)
            math(EXPR FLASH_CFG_COUNT "${FLASH_CFG_COUNT} * 2")
        endif()

        set(_mode "sectors")

    elseif(_page_sz)
        # --- Uniform-page path ------------------------------------------------
        # Used by families where all flash pages have the same size (G0, C0 …).
        # Total page count = flash size in bytes / page size in bytes.
        math(EXPR FLASH_CFG_COUNT "${_kb} * 1024 / ${_page_sz}")

        # Build the flash_sectors[] initializer list that goes into the template
        # via @FLASH_CFG_SECTORS_LIST@.  Each entry is one {address, size} line.
        # Addresses are calculated as: STM32 flash base (0x08000000) + i * page_size.
        # OUTPUT_FORMAT HEXADECIMAL makes math() emit a 0x-prefixed hex literal
        # instead of a decimal integer (requires CMake ≥ 3.13).
        math(EXPR _last "${FLASH_CFG_COUNT} - 1")
        foreach(_i RANGE 0 ${_last})
            math(EXPR _addr "0x08000000 + ${_i} * ${_page_sz}" OUTPUT_FORMAT HEXADECIMAL)
            string(APPEND FLASH_CFG_SECTORS_LIST
                "    { ${_addr}UL, ${_page_sz}UL }, // Sector ${_i}\n")
        endforeach()

        set(_mode "pages (${_page_sz} B each)")

    else()
        message(FATAL_ERROR
            "stm32_generate_flash_config: neither ${SERIES}_SECTOR_MAP "
            "nor ${SERIES}_PAGE_SIZE is defined")
    endif()

    # Variables exposed to configure_file — they replace @PLACEHOLDER@ tokens
    # inside the .h.in template:
    #   @FLASH_CFG_DEVICE@      — MCU name string  (e.g. "STM32G030C6")
    #   @FLASH_CFG_FLASH_STR@   — flash size string (e.g. "32K")
    #   @FLASH_CFG_COUNT@       — total sector / page count
    #   @FLASH_CFG_SECTORS_LIST@— pre-built initializer lines (uniform-page only)
    set(FLASH_CFG_DEVICE    "${DEVICE_NAME}")
    set(FLASH_CFG_FLASH_STR "${FLASH_STR}")

    # Substitute all @VAR@ tokens in the template and write the output header.
    # @ONLY prevents CMake from also expanding ${VAR} style references that may
    # appear in C++ comments or string literals inside the template.
    configure_file("${TEMPLATE}" "${OUT_FILE}" @ONLY)

    message(STATUS
        "Flash config generated: ${OUT_FILE}  (${FLASH_CFG_COUNT} ${_mode}, dual_bank=${STM32_DUAL_BANK})")
endfunction()
