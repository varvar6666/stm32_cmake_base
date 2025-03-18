
include(ExternalProject)

# set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
# ExternalProject_Add(cmsis
# 	GIT_REPOSITORY https://github.com/varvar6666/cmsis-core.git
# 	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
# )


include(FetchContent)

FetchContent_Declare(
	cmsis
	SOURCE_DIR ${CMAKE_SOURCE_DIR}/download_files/cmsis
	GIT_REPOSITORY https://github.com/varvar6666/cmsis-core.git
)

FetchContent_MakeAvailable(cmsis)

file(DOWNLOAD
	https://raw.githubusercontent.com/STMicroelectronics/cmsis-device-f4/refs/heads/master/Include/stm32f446xx.h
	${CMAKE_SOURCE_DIR}/download_files/Device/stm32f446xx.h)

file(DOWNLOAD
	https://raw.githubusercontent.com/STMicroelectronics/cmsis-device-f4/refs/heads/master/Include/system_stm32f4xx.h
	${CMAKE_SOURCE_DIR}/download_files/Device/system_stm32f4xx.h)