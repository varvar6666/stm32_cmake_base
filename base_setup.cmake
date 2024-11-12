
set(PROJECT_NAME ${prj_name})
set(VER 1.0)
set(DESC "Base for STM32 cmake")
set(DEVICE_FAMILY	"STM32F4")
set(DEVICE_SERIES	"STM32F446xx")
set(DEVICE 			"STM32F446RE")

# Core MCU flags, CPU, instruction set and FPU setup
set(cpu_PARAMS
    -mthumb

    # Other parameters
    # -mcpu, -mfloat, -mfloat-abi, ...
    -mcpu=cortex-m4
	-mfpu=fpv4-sp-d16
	-mfloat-abi=hard
	
)

# Linker script
set(linker_script_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f446retx_FLASH.ld
)

# Compiler options 
set(compiler_OPTS	# => target_compile_options
)

# Linker options
set(linker_OPTS 	# => target_link_options
)

# Linker script
set(linker_script_SRC
	${CMAKE_CURRENT_SOURCE_DIR}/STM32F446RETX.ld
)

# Sources
set(sources_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup.c
	${CMAKE_CURRENT_SOURCE_DIR}/Startup/vector.c
	${CMAKE_CURRENT_SOURCE_DIR}/Startup/sysmem.c
	${CMAKE_CURRENT_SOURCE_DIR}/Startup/syscalls.c

	${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/system.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/gpio.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/flash.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src/rcc.cpp
)

# Include directories
set(include_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	${CMAKE_CURRENT_SOURCE_DIR}/Drivers/src

	${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include
	${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Include
)

# Symbols definition
set(symbols_c_SYMB 

)
set(symbols_cxx_SYMB 
    
)
set(symbols_asm_SYMB
    
)

# Link directories
set(link_DIRS
    
)

# Link libraries
set(link_LIBS
    
)
