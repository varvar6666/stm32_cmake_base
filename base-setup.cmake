# ================================
# Project basic configuration
# ================================

# Имя проекта (если не задано Preset'ом)
if(NOT DEFINED prj_name)
	get_filename_component(prj_name "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
endif()

set(PROJECT_NAME ${prj_name})
set(VER 3.0)
set(DESC "Base for STM32 cmake")

# ================================
# MCU chip selection
# ================================
# DEVICE = полноценный код чипа
# Пример: STM32F446RE, STM32F103C8, STM32G431KB
set(DEVICE "STM32F429zi")

# ================================
# Drivers ON/OFF
# ================================
set(USE_DRIVERS ON)

# ================================
# Core MCU flags, CPU, instruction set and FPU setup
# ================================
set(cpu_PARAMS
	# Other parameters
)

# ================================
# Compiler options 
# ================================
set(compiler_OPTS	# => target_compile_options

)

# ================================
# Linker options
# ================================
set(linker_OPTS 	# => target_link_options
)

# ================================
# Sources
# ================================
set(sources_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/no_system_files/sysmem.c
	${CMAKE_CURRENT_SOURCE_DIR}/no_system_files/syscalls.c

	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/system.cpp
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/gpio.cpp
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/flash.cpp
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/rcc.cpp
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/uart.cpp
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/interface.cpp
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/dma.cpp
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/tim.cpp
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/math/sint.c
	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/FastMathFunctions/arm_sin_f32.c
)

# ================================
# Include directories
# ================================
set(include_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}/inc

	# ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/math
)

if(USE_DRIVERS)
	list(APPEND include_DIRS
		${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src
	)
endif()

# ================================
# Extra user defines (если нужны)
# ================================
set(symbols_c_SYMB "")
set(symbols_cxx_SYMB "")
set(symbols_asm_SYMB "")

# ================================
# Extra user options / libs
# ================================
set(link_DIRS "")
set(link_LIBS "")