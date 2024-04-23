
set(PROJECT_NAME ${prj_name})

set(CXX_STD_VERSION 20)
set(VER 1.0)
set(DESC "Base for STM32 cmake")
set(DEVICE_FAMILY	"STM32F4")
set(DEVICE_SERIES	"STM32F446xx")
set(DEVICE 			"STM32F446RE")

set(inc_dirs 
	"inc/"
	"Drivers/CMSIS/Include/"
	"Drivers/CMSIS/Device/ST/STM32F4xx/Include/"
	"Drivers/src/"
	)

set(src_dirs
	"src/"
	"Drivers/src/"
	"Startup/"
	)

set(linker_script "${CMAKE_CURRENT_LIST_DIR}/STM32F446RETX.ld")
set(linker_params "-Wl,--no-warn-rwx-segment")
