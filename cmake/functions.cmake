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

# ---------------------------------------------------------------------------
# stm32_generate_flash_config(SERIES FLASH_STR DEVICE_NAME TEMPLATE OUT_FILE)
#
# Looks up FLASH_KB in ${SERIES}_SECTOR_MAP to get single-bank sector count.
# If STM32_DUAL_BANK is ON, count is doubled.
# TEMPLATE — path to the downloaded .h.in file.
#
# ${SERIES}_SECTOR_MAP record format: FLASH_KB  SECTOR_COUNT  (2 fields)
# ---------------------------------------------------------------------------
function(stm32_generate_flash_config SERIES FLASH_STR DEVICE_NAME TEMPLATE OUT_FILE)

    k_to_int("${FLASH_STR}" _kb)

    set(_map "${${SERIES}_SECTOR_MAP}")
    if(NOT _map)
        message(WARNING "stm32_generate_flash_config: ${SERIES}_SECTOR_MAP not defined — skipping")
        return()
    endif()

    list(FIND _map "${_kb}" _idx)
    if(_idx LESS 0)
        message(FATAL_ERROR "stm32_generate_flash_config: no entry for ${_kb}K in ${SERIES}_SECTOR_MAP")
    endif()

    math(EXPR _i1 "${_idx} + 1")
    list(GET _map ${_i1} FLASH_CFG_COUNT)

    if(STM32_DUAL_BANK)
        math(EXPR FLASH_CFG_COUNT "${FLASH_CFG_COUNT} * 2")
    endif()

    set(FLASH_CFG_DEVICE    "${DEVICE_NAME}")
    set(FLASH_CFG_FLASH_STR "${FLASH_STR}")

    configure_file("${TEMPLATE}" "${OUT_FILE}" @ONLY)

    message(STATUS "Flash config generated: ${OUT_FILE}  (${FLASH_CFG_COUNT} sectors, dual_bank=${STM32_DUAL_BANK})")
endfunction()
