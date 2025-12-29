cmake_minimum_required(VERSION 3.22)
################################## BASE SETUP ###############################################################

include("./base_setup.cmake")
include("cmake/gcc-arm-none-eabi.cmake")

################################## PORJECT SETUP ###############################################################
if("${PROJECT_NAME}" STREQUAL "")
	get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
	string(REPLACE " " "_" PROJECT_NAME ${PROJECT_NAME})
	message(STATUS "Project name Not set. Use name: ${PROJECT_NAME}")
else()
	message(STATUS "Project name: ${PROJECT_NAME}")
endif()

project(${PROJECT_NAME}  	VERSION ${VER}
							DESCRIPTION ${DESC}
							LANGUAGES C CXX ASM)

message("Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "CMAKE Project name: ${CMAKE_PROJECT_NAME}")

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# message(STATUS "Compiler path: ${CMAKE_CXX_COMPILER}")
# message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
# message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
# message(STATUS "Compiler is part of GCC: ${CMAKE_COMPILER_IS_GNUCXX}")

include("cmake/stm32-parse-device.cmake")

stm32_parse_device(${DEVICE})

#donwnload cmsis
include("cmake/cmsis-download.cmake")


# Linker script
set(linker_script_SRC_mcu
	${CMAKE_SOURCE_DIR}/download_files/linker/${linker_name}
)
set(linker_script_SRC_common
	${CMAKE_SOURCE_DIR}/download_files/linker/common.ld
)

# Link directories setup
# Must be before executable is added
link_directories(${CMAKE_PROJECT_NAME} ${link_DIRS})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add sources to executable
list(APPEND sources_SRCS ${CMAKE_SOURCE_DIR}/download_files/startup/${irq_vector})
list(APPEND sources_SRCS ${CMAKE_SOURCE_DIR}/download_files/startup/startup_common.c)
target_sources(${CMAKE_PROJECT_NAME} PUBLIC ${sources_SRCS})

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${include_DIRS})

################################## TARGET DEFINITIONS ###############################################################
target_compile_definitions(
	${CMAKE_PROJECT_NAME} PRIVATE
	${symbols_SYMB}
	${c_target}
	${STM32_DEVICE_UC}
	${STM32_CORE}
	${STM32_FLASH_def}
	$<$<COMPILE_LANGUAGE:C>: ${symbols_c_SYMB}>
	$<$<COMPILE_LANGUAGE:CXX>: ${symbols_cxx_SYMB}>
	$<$<COMPILE_LANGUAGE:ASM>: ${symbols_asm_SYMB}>

	# Configuration specific
	$<$<CONFIG:Debug>:DEBUG>
	$<$<CONFIG:Release>: >
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME} ${link_LIBS})

# Compiler options
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
	-mthumb
	${main_cpu_PARAMS}
	${cpu_PARAMS}
	${compiler_OPTS}
	-Wall
	-Wextra
	-Wpedantic
	-Wno-unused-parameter
	$<$<COMPILE_LANGUAGE:C>: >
	$<$<COMPILE_LANGUAGE:CXX>:

	# -Wno-volatile
	# -Wold-style-cast
	# -Wuseless-cast
	# -Wsuggest-override
	>
	$<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp -MMD -MP>
	$<$<CONFIG:Debug>:-Og -g3 -ggdb>
	$<$<CONFIG:Release>:-Og -g0>
)

################################## LINK OPTIONS ###############################################################

# Linker options
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
	-L${CMAKE_SOURCE_DIR}/download_files/linker
	-T${linker_script_SRC_mcu}
	${main_cpu_PARAMS}
	${cpu_PARAMS}
	${linker_OPTS}
	"-Wl,-Map=${CMAKE_PROJECT_NAME}.map"
	"-u _printf_float" # STDIO float formatting support (remove if not used)
	"--specs=nosys.specs"
	"-Wl,--start-group"
	"-lc"
	"-lm"
	"-lstdc++"
	"-lsupc++"
	"-Wl,--end-group"
	"-Wl,-z,max-page-size=8" # Allow good software remapping across address space (with proper GCC section making)
	"-Wl,--print-memory-usage"
)

################################## POST ###############################################################

# Execute post-build to print size, generate hex and bin
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
	COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.hex
	COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.bin
)