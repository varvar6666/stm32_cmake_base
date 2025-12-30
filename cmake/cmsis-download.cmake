include(FetchContent)

string(TOLOWER ${DEVICE} STM32_DEVICE_LC)
string(TOUPPER ${DEVICE} STM32_DEVICE_UC)
message(STATUS "Device_LC: " ${STM32_DEVICE_LC})
message(STATUS "Device_UC: " ${STM32_DEVICE_UC})
#string(TOLOWER ${DEVICE} ${DEVICE})

string(SUBSTRING "${STM32_DEVICE_UC}" 0 7 STM32_CORE)
string(SUBSTRING "${STM32_DEVICE_UC}" 0 11 STM32_FLASH_def) # todo
string(SUBSTRING "${STM32_DEVICE_UC}" 0 9 STM32_MODEL_UC)
string(SUBSTRING "${STM32_DEVICE_UC}" 10 1 last_letter)

set(STM32_SERIES_UC "${STM32_CORE}xx")
set(linker_name "${STM32_MODEL_UC}x${last_letter}.ld") 
string(TOLOWER ${STM32_MODEL_UC} STM32_MODEL_LC)
string(TOLOWER ${STM32_SERIES_UC} STM32_SERIES_LC)
set(c_target "${STM32_MODEL_UC}xx") # todo choose base on STM32_CORE

message(STATUS "STM32_CORE: 	 " ${STM32_CORE})
message(STATUS "STM32_FLASH_def:" ${STM32_FLASH_def})
message(STATUS "STM32_SERIES_UC: " ${STM32_SERIES_UC})
message(STATUS "STM32_SERIES_LC: " ${STM32_SERIES_LC})
message(STATUS "STM32_MODEL_UC: " ${STM32_MODEL_UC})
message(STATUS "STM32_MODEL_LC: " ${STM32_MODEL_LC})
message(STATUS "linker_name: " ${linker_name}) # todo
message(STATUS "last_letter: " ${last_letter}) # todo
message(STATUS "c_target: " ${c_target})


# ============================================================================================================================================
# get name for vector table and header file
# ============================================================================================================================================
include(${CMAKE_SOURCE_DIR}/cmake/functions.cmake)

download_one(
	"STM32-map.cmake"
	"${CMAKE_SOURCE_DIR}/download_files/cmake"
	"cmake/${STM32_CORE}-map.cmake")

include(${CMAKE_SOURCE_DIR}/download_files/cmake/STM32-map.cmake)
# ============================
# lookup name
# ============================
list(FIND ${STM32_CORE}_MAP "${STM32_DEVICE_UC}" IDX)

if(IDX LESS 0)
  message(FATAL_ERROR "No Name for ${STM32_DEVICE_UC}")
endif()

math(EXPR IDX_NAME   "${IDX} + 1")
math(EXPR IDX_FLASH  "${IDX} + 2")
math(EXPR IDX_RAM    "${IDX} + 3")
math(EXPR IDX_EXTRA  "${IDX} + 4")

list(GET ${STM32_CORE}_MAP ${IDX_NAME}  STM32_NAME)
list(GET ${STM32_CORE}_MAP ${IDX_FLASH} STM32_FLASH)
list(GET ${STM32_CORE}_MAP ${IDX_RAM}   STM32_RAM)
list(GET ${STM32_CORE}_MAP ${IDX_EXTRA} STM32_EXTRA)

message(STATUS "STM32_NAME   = ${STM32_NAME}")

# ============================================================================================================================================
# download svd from series and model - STM32F4/STM32F4xx.svd
# ============================================================================================================================================

download_one(
	"SVD.svd"
	"${CMAKE_SOURCE_DIR}/download_files"
	"SVD/${STM32_SERIES_UC}/${STM32_MODEL_UC}.svd")

# ============================================================================================================================================
# download startup and vetor files
# ============================================================================================================================================

download_one(
	"startup_common.c"
	"${CMAKE_SOURCE_DIR}/download_files/startup"
	"startup_c/startup_common.c")

download_one(
	"vector_${STM32_NAME}.c"
	"${CMAKE_SOURCE_DIR}/download_files/startup"
	"startup_c/${STM32_SERIES_UC}/vector_${STM32_NAME}.c")

# ============================================================================================================================================
# download STM32 headers files and system files
# ============================================================================================================================================

download_one(
	"${STM32_SERIES_LC}.h"
	"${CMAKE_SOURCE_DIR}/download_files/Device/Include"
	"Device/${STM32_SERIES_UC}/Include/${STM32_SERIES_LC}.h")

download_one(
	"system_${STM32_SERIES_LC}.h"
	"${CMAKE_SOURCE_DIR}/download_files/Device/Include"
	"Device/${STM32_SERIES_UC}/Include/system_${STM32_SERIES_LC}.h")

download_one(
	"system_${STM32_SERIES_LC}.c"
	"${CMAKE_SOURCE_DIR}/download_files/Device/Source"
	"Device/${STM32_SERIES_UC}/Source/system_${STM32_SERIES_LC}.c")

download_one(
	"${STM32_NAME}.h"
	"${CMAKE_SOURCE_DIR}/download_files/Device/Include"
	"Device/${STM32_SERIES_UC}/Include/${STM32_NAME}.h")

# ============================================================================================================================================
# Configure and download linker files
# ============================================================================================================================================

message(STATUS "Using linker script : ${LD_TEMPLATE}")
message(STATUS "FLASH               : ${STM32_FLASH}")
message(STATUS "RAM                 : ${STM32_RAM}")
message(STATUS "EXTRA               : ${STM32_EXTRA}")

set(FLASH_ORIGIN 0x08000000)
set(FLASH_LENGTH ${STM32_FLASH})

set(RAM_ORIGIN 0x20000000)
set(RAM_LENGTH ${STM32_RAM})

set(HEAP_SIZE 0x200)
set(STACK_SIZE 0x400)


if(STM32_CORE STREQUAL "STM32F7")
	set(LD_TEMPLATE "linker-f7.ld.in")

	set(ITCM_ORIGIN 0x00000000)
	set(ITCM_LENGTH 16K)

	set(DTCM_ORIGIN 0x20000000)
	set(DTCM_LENGTH ${STM32_EXTRA})   # 64K или 128K

	set(SRAM2_LENGTH 16K)

	if(STM32_EXTRA STREQUAL "64K")
		set(SRAM2_ORIGIN 0x2004C000)

		set(SRAM1_ORIGIN 0x20010000)
	elseif(STM32_EXTRA STREQUAL "128K")
		set(SRAM2_ORIGIN 0x2007C000)

		set(SRAM1_ORIGIN 0x20020000)
	else()
		message(FATAL_ERROR "Invalid DTCM size for F7: ${STM32_EXTRA}")
	endif()

	k_to_int("${STM32_RAM}"   RAM_K)
	k_to_int("${DTCM_LENGTH}" DTCM_K)
	k_to_int("${SRAM2_LENGTH}" SRAM2_K)

	math(EXPR SRAM1_K
		"${RAM_K} - ${DTCM_K} - ${SRAM2_K}"
	)

	set(SRAM1_LENGTH "${SRAM1_K}K")

elseif(STM32_CORE STREQUAL "STM32H7")
	set(LD_TEMPLATE "linker-h7.ld.in")
elseif(STM32_EXTRA AND NOT STM32_EXTRA STREQUAL "-" AND NOT STM32_EXTRA STREQUAL "0K")
	set(LD_TEMPLATE "linker-ccm.ld.in")

	set(CCM_ORIGIN 0x10000000)
	set(CCM_LENGTH ${STM32_EXTRA})

	k_to_int("${STM32_RAM}"   RAM_K)
	k_to_int("${CCM_LENGTH}"  CCM_K)

	math(EXPR SRAM1_K
		"${RAM_K} - ${CCM_K}"
	)

	set(RAM_LENGTH "${SRAM1_K}K")
else()
	set(LD_TEMPLATE "linker-simple.ld.in")
endif()


download_one(
	"${LD_TEMPLATE}"
	"${CMAKE_SOURCE_DIR}/download_files/linker"
	"linker/${LD_TEMPLATE}")

set(LD_IN  ${CMAKE_SOURCE_DIR}/download_files/linker/${LD_TEMPLATE})
set(LD_OUT ${CMAKE_SOURCE_DIR}/download_files/linker/${STM32_DEVICE_LC}.ld)

configure_file(
  ${LD_IN}
  ${LD_OUT}
  @ONLY
)


message(STATUS "Linker script generated: ${LD_OUT}")


# ============================================================================================================================================
# Download drivers (optional)
# ============================================================================================================================================


# message("USE_DRIVERS = ${USE_DRIVERS}")

# if(${USE_DRIVERS} EQUAL 1)
# 	file(GLOB RESULT "${CMAKE_SOURCE_DIR}/Drivers")
# 	list(LENGTH RESULT RES_LEN)
	
# 	if(RES_LEN EQUAL 0)
# 		message(STATUS "Downloading Drivers" )
# 		## Download ARM Core
# 		FetchContent_Declare(
# 			Drivers
# 			SOURCE_DIR ${CMAKE_SOURCE_DIR}/Drivers
# 			GIT_REPOSITORY git@github.com:varvar6666/STM32_Drivers_CPP.git
# 			GIT_TAG "origin/main"
# 		)

# 		FetchContent_MakeAvailable(Drivers)
# 	else()
# 		message(STATUS "Drivers Already downloaded" )
# 	endif()
# endif()
