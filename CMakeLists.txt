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

# Link directories setup
# Must be before executable is added
link_directories(${CMAKE_PROJECT_NAME} ${link_DIRS})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PUBLIC ${sources_SRCS})

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${include_DIRS})

################################## TARGET DEFINITIONS ###############################################################

target_compile_definitions(
	${CMAKE_PROJECT_NAME} PRIVATE
	${symbols_SYMB}
	${DEVICE_FAMILY}
	${DEVICE_SERIES}
	${DEVICE}
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

# target_compile_options(
# 	${PROJECT_NAME} PRIVATE
# 	# CPU specific
# 	"-mcpu=cortex-m4"
# 	"-mfloat-abi=hard"
# 	"-mthumb"
# 	"-mfpu=fpv4-sp-d16"
# 	# Other options
# 	"-g3"
# 	"-c"
# 	"-O0"
# 	"-Wall"
# 	"-Wno-deprecated"
# )

################################## LINK OPTIONS ###############################################################

# Linker options
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
	-T${linker_script_SRC}
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

# target_link_options(
# 	${PROJECT_NAME} PRIVATE
# 	"-mcpu=cortex-m4"
# 	"-mfpu=fpv4-sp-d16"
# 	"-mfloat-abi=hard"
# 	"-Wl,--print-memory-usage"
# 	${linker_params}
# 	-T ${linker_script}
# )

################################## POST ###############################################################

# Execute post-build to print size, generate hex and bin
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
	COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.hex
	COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.bin
)


# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
# )

# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_OBJCOPY} -O ihex
#     $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
# )

# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_OBJCOPY} -O binary
#     $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.bin
# )