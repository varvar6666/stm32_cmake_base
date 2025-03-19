
if(${Core} STREQUAL "STM32F4")
	set(main_cpu_PARAMS
		-mcpu=cortex-m4
		-mfpu=fpv4-sp-d16
		-mfloat-abi=hard
	)
	message(STATUS "Set main cpu params for STM32F4")

elseif(${Core} STREQUAL "STM32F7")
	set(main_cpu_PARAMS
		-mcpu=cortex-m7
		-mfpu=fpv4-sp-d16
		-mfloat-abi=hard
	)
	message(STATUS "Set main cpu params for STM32L0")

elseif(${Core} STREQUAL "STM32L0")
	set(main_cpu_PARAMS
		"-mcpu=cortex-m0plus"
	)
	message(STATUS "Set main cpu params for STM32L0")

else()
	message(FATAL_ERROR "Cannot found CPU params")
endif()
