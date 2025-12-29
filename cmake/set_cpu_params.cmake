# =======================================================================
#  set_cpu_params.cmake
#  Определяет CPU-флаги по серии STM32 (без вложенных IF, без функций)
# =======================================================================

if(NOT DEFINED Core)
	message(FATAL_ERROR "[set_cpu_params] Variable 'Core' must be set by cmsis-download.cmake")
endif()

# Core = "STM32F4", "STM32F7", "STM32L0", "STM32F1" и т.д.
message(STATUS "[set_cpu_params] Core detected: ${Core}")

# =======================================================================
# CPU FLAGS (main_cpu_PARAMS)
# =======================================================================

if("${Core}" STREQUAL "STM32F0")
	set(main_cpu_PARAMS
		-mcpu=cortex-m0
		-mthumb
	)

elseif("${Core}" STREQUAL "STM32L0")
	set(main_cpu_PARAMS
		-mcpu=cortex-m0plus
		-mthumb
	)

elseif("${Core}" STREQUAL "STM32F1" OR "${Core}" STREQUAL "STM32F2")
	set(main_cpu_PARAMS
		-mcpu=cortex-m3
		-mthumb
	)

elseif("${Core}" STREQUAL "STM32F3" OR "${Core}" STREQUAL "STM32F4" OR "${Core}" STREQUAL "STM32L4" OR "${Core}" STREQUAL "STM32G4")
	set(main_cpu_PARAMS
		-mcpu=cortex-m4
		-mthumb
		-mfpu=fpv4-sp-d16
		-mfloat-abi=hard
	)

elseif("${Core}" STREQUAL "STM32F7")
	set(main_cpu_PARAMS
		-mcpu=cortex-m7
		-mthumb
		-mfpu=fpv5-sp-d16
		-mfloat-abi=hard
	)

elseif("${Core}" STREQUAL "STM32H7")
	set(main_cpu_PARAMS
		-mcpu=cortex-m7
		-mthumb
		-mfpu=fpv5-d16
		-mfloat-abi=hard
	)

else()
	message(FATAL_ERROR "[set_cpu_params] Unsupported Core: ${Core}")
endif()

message(STATUS "[set_cpu_params] CPU flags: ${main_cpu_PARAMS}")
