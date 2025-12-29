
set(PROJECT_NAME ${prj_name})
set(VER 3.0)
set(DESC "Base for STM32 cmake")
set(DEVICE 	"STM32F446ret")

set(USE_DRIVERS 0) #1 - USE drivers , 0 - bare metal

# Core MCU flags, CPU, instruction set and FPU setup
set(cpu_PARAMS
	# Other parameters
)

# Compiler options 
set(compiler_OPTS	# => target_compile_options

)

# Linker options
set(linker_OPTS 	# => target_link_options
)

# Sources
set(sources_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/no_system_files/sysmem.c
	${CMAKE_CURRENT_SOURCE_DIR}/no_system_files/syscalls.c

)

# Include directories
set(include_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}/inc

	${CMAKE_CURRENT_SOURCE_DIR}/download_files/cmsis/Core/Include
	${CMAKE_CURRENT_SOURCE_DIR}/download_files/Device/Include
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
