
set(PROJECT_NAME vs_cmake)

set(CXX_STD_VERSION 20)
set(VER 1.0)
set(DESC "Base for STM32 cmake")
set(DEVICE "STM32F446xx")

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

