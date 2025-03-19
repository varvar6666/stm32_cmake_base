include(FetchContent)

string(TOLOWER ${DEVICE} dev_lc)
string(TOUPPER ${DEVICE} dev_uc)
message("Device_lc: " ${dev_lc})
message("Device_uc: " ${dev_uc})
#string(TOLOWER ${DEVICE} ${DEVICE})

string(SUBSTRING "${dev_uc}" 0 7 Core)
string(SUBSTRING "${dev_uc}" 0 9 Model)
string(SUBSTRING "${dev_uc}" 10 1 last_letter)

set(Series "${Core}xx")
set(linker_name "${Model}x${last_letter}.ld") 
string(TOLOWER ${Model} Model_lc)
string(TOLOWER ${Series} Series_lc)
set(c_target "${Model}xx") # todo choose base on core

message("Core: " ${Core})
message("Series: " ${Series})
message("Series_lv: " ${Series_lc})
message("Model: " ${Model})
message("Model_lc: " ${Model_lc})
message("linker_name: " ${linker_name})
message("last_letter: " ${last_letter})
message("c_target: " ${c_target})


file(GLOB RESULT "${CMAKE_SOURCE_DIR}/download_files/cmsis")
list(LENGTH RESULT RES_LEN)

if(RES_LEN EQUAL 0)
	message(STATUS "Downloading ARM Core" )
	## Download ARM Core
	FetchContent_Declare(
		cmsis
		SOURCE_DIR ${CMAKE_SOURCE_DIR}/download_files/cmsis
		GIT_REPOSITORY https://github.com/varvar6666/cmsis-core.git
	)

	FetchContent_MakeAvailable(cmsis)
else()
	message(STATUS "ARM Core already downloaded")
endif()


if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/SVD.svd)
	message(STATUS "SVD file already downloaded")
else()
	file(DOWNLOAD	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/SVD/${Series}/${Model}.svd
		STATUS DOWNLOAD_RESULT
		${CMAKE_SOURCE_DIR}/download_files/SVD.svd)

	message(STATUS "Downloading SVD file Series-${Series}, ${Model}.svd -> SVD.svd. Result: ${DOWNLOAD_RESULT}" )
endif()


if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/linker/common.ld)
	message(STATUS "Common Linker file already downloaded")
else()
	file(DOWNLOAD	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/linker/common.ld
		STATUS DOWNLOAD_RESULT
		${CMAKE_SOURCE_DIR}/download_files/linker/common.ld)

	message(STATUS "Downloading Common Linker file. Result: ${DOWNLOAD_RESULT}" )
endif()


if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/linker/${linker_name})
	message(STATUS "Linker file already downloaded")
else()
	file(DOWNLOAD	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/linker/${Series}/${linker_name}
		STATUS DOWNLOAD_RESULT
		${CMAKE_SOURCE_DIR}/download_files/linker/${linker_name})

	message(STATUS "Downloading Linker file Series-${Series}, ${linker_name}. Result: ${DOWNLOAD_RESULT}" )
endif()


if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/startup/startup_common.c)
	message(STATUS "Common Startup file already downloaded")
else()
	file(DOWNLOAD	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/startup_c/startup_c_common.c
		STATUS DOWNLOAD_RESULT
		${CMAKE_SOURCE_DIR}/download_files/startup/startup_common.c)

	message(STATUS "Downloading Common Startup file startup_common.c. Result: ${DOWNLOAD_RESULT}" )
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/temp/startup_c)
	message(STATUS "List of IRQ file already downloaded")
else()
	file(DOWNLOAD	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/startup_c/${Series}/files_list.txt
		STATUS DOWNLOAD_RESULT
		${CMAKE_SOURCE_DIR}/download_files/temp/startup_c)

	message(STATUS "Downloading list of IRQ vectors ${Series}. Result: ${DOWNLOAD_RESULT}" )
endif()


file(STRINGS "${CMAKE_SOURCE_DIR}/download_files/temp/startup_c" this)

set(found "")
set(irq_vector "")

while(this)
	list(POP_FRONT this LINE)
	if(LINE MATCHES "${Model_lc}")
		list(APPEND found ${LINE})
	endif()
	
endwhile(this)

message("Check list of IRQ vectors, found: ${found}")


list(LENGTH found found_list_length)
if(found_list_length EQUAL 0)
	message(FATAL_ERROR "No IRQ vector")
elseif(found_list_length EQUAL 1)
	list(GET found 0 irq_vector)
	message(STATUS "Found 1 IRQ vector - ${irq_vector}")
else()
	message("Found ${found_list_length} IRQ vector")
	if(${Model_lc} STREQUAL "stm32f401")
		if(${last_letter} STREQUAL "E")
			list(GET found 1 irq_vector)
		elseif(${last_letter} STREQUAL "C")
			list(GET found 0 irq_vector)
		else()
			message(FATAL_ERROR "WRONG MCU")
		endif()
	else()
		string(SUBSTRING "${dev_lc}" 0 10 model_x)
		while(found)
			list(POP_FRONT found LINE)
			if(LINE MATCHES ${model_x})
				set(irq_vector ${LINE})
			endif()
		endwhile(found)
	endif()

	if("${irq_vector}" STRLESS_EQUAL "")
		message(FATAL_ERROR "Can't find IRQ vector")
	else()
		message(STATUS "USE IRQ vector - ${irq_vector}")
	endif()

endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/startup/${irq_vector})
	message(STATUS "IRQ Vector file already downloaded")
else()
	file(DOWNLOAD	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/startup_c/${Series}/${irq_vector}
		STATUS DOWNLOAD_RESULT
		${CMAKE_SOURCE_DIR}/download_files/startup/${irq_vector})

	message(STATUS "Downloading IRQ Vector Series-${Series}, ${irq_vector}. Result: ${DOWNLOAD_RESULT}" )
endif()


if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/Device/Include/${Series_lc}.h)
	message(STATUS "MCU Series Header file already downloaded")
else()
file(DOWNLOAD
	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/Device/${Series}/Include/${Series_lc}.h
	${CMAKE_SOURCE_DIR}/download_files/Device/Include/${Series_lc}.h)

	message(STATUS "Downloading MCU Series Header-${Series}, ${Series_lc}.h. Result: ${DOWNLOAD_RESULT}" )
endif()


if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/Device/Include/system_${Series_lc}.h)
	message(STATUS "MCU Series system header file already downloaded")
else()
	file(DOWNLOAD
		https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/Device/${Series}/Include/system_${Series_lc}.h
		${CMAKE_SOURCE_DIR}/download_files/Device/Include/system_${Series_lc}.h)

	message(STATUS "Downloading MCU Series system header-${Series}, system_${Series_lc}.h. Result: ${DOWNLOAD_RESULT}" )
endif()


if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/Device/Source/system_${Series_lc}.c)
	message(STATUS "MCU Series system source file already downloaded")
else()
	file(DOWNLOAD
		https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/Device/${Series}/Source/system_${Series_lc}.c
		${CMAKE_SOURCE_DIR}/download_files/Device/Source/system_${Series_lc}.c)

	message(STATUS "Downloading MCU Series system source-${Series}, system_${Series_lc}.c. Result: ${DOWNLOAD_RESULT}" )
endif()


if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/temp/headers)
	message(STATUS "List of MCU headers file already downloaded")
else()
	file(DOWNLOAD	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/Device/${Series}/Include/files_list.txt
		STATUS DOWNLOAD_RESULT
		${CMAKE_SOURCE_DIR}/download_files/temp/headers)

	message(STATUS "Downloading list of MCU headers ${Series}. Result: ${DOWNLOAD_RESULT}" )
endif()


file(STRINGS "${CMAKE_SOURCE_DIR}/download_files/temp/headers" this)

set(found "")
set(header "")

while(this)
	list(POP_FRONT this LINE)
	if(LINE MATCHES "${Model_lc}")
		list(APPEND found ${LINE})
	endif()
	
endwhile(this)

message("Check list of MCU headers, found: ${found}")


list(LENGTH found found_list_length)
if(found_list_length EQUAL 0)
	message(FATAL_ERROR "No MCU Headers")
elseif(found_list_length EQUAL 1)
	list(GET found 0 header)
	message(STATUS "Found 1 MCU Header - ${header}")
else()
	message("Found ${found_list_length} MCU Headers")
	if(${Model_lc} STREQUAL "stm32f401")
		if(${last_letter} STREQUAL "E")
			list(GET found 1 header)
		elseif(${last_letter} STREQUAL "C")
			list(GET found 0 header)
		else()
			message(FATAL_ERROR "WRONG MCU")
		endif()
	else()
		string(SUBSTRING "${dev_lc}" 0 10 model_x)
		while(found)
			list(POP_FRONT found LINE)
			if(LINE MATCHES ${model_x})
				set(header ${LINE})
			endif()
		endwhile(found)
	endif()

	if("${header}" STRLESS_EQUAL "")
		message(FATAL_ERROR "Can't find MCU Header")
	else()
		message(STATUS "USE Header - ${header}")
	endif()

endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/download_files/Device/Include/${header})
	message(STATUS "MCU Header file already downloaded")
else()
	file(DOWNLOAD	https://raw.githubusercontent.com/varvar6666/STM32-base_files/refs/heads/master/Device/${Series}/Include/${header}
		STATUS DOWNLOAD_RESULT
		${CMAKE_SOURCE_DIR}/download_files/Device/Include/${header})

	message(STATUS "Downloading MCU Header Series-${Series}, ${header}. Result: ${DOWNLOAD_RESULT}" )
endif()


message("USE_DRIVERS = ${USE_DRIVERS}")
if(${USE_DRIVERS} EQUAL 1)
	message(STATUS "Downloading ARM Core" )
	## Download ARM Core
	FetchContent_Declare(
		Drivers
		SOURCE_DIR ${CMAKE_SOURCE_DIR}/Drivers
		GIT_REPOSITORY git@github.com:varvar6666/STM32_Drivers_CPP.git
	)

	FetchContent_MakeAvailable(Drivers)
endif()
