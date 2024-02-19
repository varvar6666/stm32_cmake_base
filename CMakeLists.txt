cmake_minimum_required(VERSION 3.20)

# Specify C, C++ and ASM compilers
set(CMAKE_SYSTEM_NAME "Generic")
SET(CMAKE_C_COMPILER    ${TOOLCHAIN_PATH}arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER  ${TOOLCHAIN_PATH}arm-none-eabi-g++)
set(AS                  ${TOOLCHAIN_PATH}arm-none-eabi-as)
set(AR                  ${TOOLCHAIN_PATH}arm-none-eabi-ar)
set(OBJCOPY             ${TOOLCHAIN_PATH}arm-none-eabi-objcopy)
set(OBJDUMP             ${TOOLCHAIN_PATH}arm-none-eabi-objdump)
set(SIZE                ${TOOLCHAIN_PATH}arm-none-eabi-size)
set(GDB                 ${TOOLCHAIN_PATH}arm-none-eabi-gdb)
set(SIZE                ${TOOLCHAIN_PATH}arm-none-eabi-size)
set(CMAKE_ASM_COMPILER  ${TOOLCHAIN_PATH}arm-none-eabi-gcc)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(PROJECT_NAME vs_cmake)

project(${PROJECT_NAME} 	VERSION 1.0
							DESCRIPTION "Very nice project"
							LANGUAGES C CXX ASM)

SET(CMAKE_CXX_STANDARD 20)

set(linker_script "${CMAKE_CURRENT_LIST_DIR}/STM32F446RETX.ld")
set(device_name "STM32F446xx")

set(c_compile_options
	# CPU specific
	"-mcpu=cortex-m4"
	"-mfloat-abi=hard"
	"-mthumb"
	# Non-CPU specific
	"--specs=nano.specs"
	"-ffunction-sections"
	"-fdata-sections"
	"-fstack-usage"
	# Other options
	"-g3"
	"-c"
	"-Os"
	"-Wall"
)
	
set(compile_definitions "${device_name}")
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	list(APPEND compile_definitions "DEBUG" "_DEBUG")
else()
	list(APPEND compile_definitions "NDEBUG")
endif()
# Linker script path
# file(GLOB_RECURSE LINKER_SCRIPT *.ld)

set(link_flags
	"-mcpu=cortex-m4 \
	-mfloat-abi=hard \
	-Wl,-Map=\"${PROJECT_NAME}.map\" \
	-Wl,--gc-sections \
	-static \
	--specs=nano.specs \
	-Wl,--start-group -lc -lm -Wl,--end-group \
    -T ${linker_script}"
)

add_compile_options("${c_compile_options}")
add_compile_definitions("${compile_definitions}")



################################## Source code ###############################################################
# Retrieve all sources # "platforms/${FAMILY}/Startup/*.s"
# file(GLOB SOURCES  "src/*.с" "src/*.cpp")
#Retrieve all locations of headers
file(GLOB_RECURSE HEADERS "Drivers/CMSIS/Include/*.h"  "Drivers/CMSIS/Device/ST/STM32F4xx/Include/*.h")
set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)
include_directories(${INCLUDE_DIRS})

# link_directories(${ARM_LIB})
################################## Source code END ###########################################################

# message(STATUS "src \"${SOURCES}\"")

set(SOURCES "src/main.cpp" "Startup/startup_stm32f446retx.s")# "src/startup.c")
add_executable("${PROJECT_NAME}" ${SOURCES} ${LINKER_SCRIPT})
set_target_properties("${PROJECT_NAME}" PROPERTIES LINK_FLAGS "${link_flags}")

# message(STATUS "build \"${CMAKE_BUILD_TYPE}\"")

# The OBJCOPY utility will separate the EEPROM section from the main program
add_custom_command(TARGET "${PROJECT_NAME}" POST_BUILD
	COMMAND "${CMAKE_OBJCOPY}" ARGS -j .eeprom "$<TARGET_FILE:${PROJECT_NAME}>" -O ihex "eeprom.hex"
	COMMAND "${CMAKE_OBJCOPY}" ARGS -R .eeprom "$<TARGET_FILE:${PROJECT_NAME}>" "program.elf"
	BYPRODUCTS "eeprom.hex" "program.elf"
)