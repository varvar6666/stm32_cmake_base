# Usage:
#   stm32_parse_device(STM32F446RET)
#
# Exports variables:
#   STM32_DEVICE_UC      STM32F446RET
#   STM32_FAMILY         F
#   STM32_LINE           446
#   STM32_LINE_SHORT     44        (for grouping)
#   STM32_MODEL          STM32F446
#   STM32_MODEL_LC       stm32f446
#   STM32_PACKAGE_CODE   R
#   STM32_MEM_CODE       E
#   STM32_PACKAGE        RET
#   STM32_REVISION_CODE  T

function(stm32_parse_device DEVICE)

	string(TOUPPER "${DEVICE}" DEV)

	string(SUBSTRING "${DEV}" 0 7 STM32_MODEL)   # STM32F446
	string(SUBSTRING "${DEV}" 9 1 STM32_PACKAGE) # R
	string(SUBSTRING "${DEV}" 10 1 STM32_MEM)     # E

	set(STM32_MODEL "${STM32_MODEL}" PARENT_SCOPE)
	set(STM32_PACKAGE "${STM32_PACKAGE}" PARENT_SCOPE)
	set(STM32_MEM "${STM32_MEM}" PARENT_SCOPE)

	message(STATUS "mod ${STM32_MODEL}")
endfunction()
