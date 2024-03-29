#Copy this file to the application project folder as CMakeLists.txt
cmake_minimum_required (VERSION 3.6)

# Grab the SDK location
if(NOT DEFINED SOS_SDK_PATH)
	if(DEFINED ENV{SOS_SDK_PATH})
		set(SOS_SDK_PATH $ENV{SOS_SDK_PATH})
	elseif( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin" )
		message(WARNING "default SDK locations are deprecated")
		set(SOS_SDK_PATH /Applications/StratifyLabs-SDK)
	elseif( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows" )
		message(WARNING "default SDK locations are deprecated")
		set(SOS_SDK_PATH C:/StratifyLabs-SDK)
	elseif( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux" )
		message(WARNING "default SDK locations are deprecated")
		set(SOS_SDK_PATH /StratifyLabs-SDK)
	endif()
endif()
if(NOT DEFINED SOS_SDK_PATH)
	message(FATAL_ERROR "Please set environment variable SOS_SDK_PATH to location of the StratifyLabs-SDK directory")
endif()
set(SOS_TOOLCHAIN_CMAKE_PATH ${SOS_SDK_PATH}/Tools/gcc/arm-none-eabi/cmake)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-variables.cmake)

# Override standard SOS variables here
if( ${SOS_BUILD_CONFIG} STREQUAL arm )
	set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-toolchain.cmake)
elseif( ${SOS_BUILD_CONFIG} STREQUAL link )
	set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/link-toolchain.cmake)
endif()

# This will set the default RAM used by the application
set(SOS_RAM_SIZE 32768)

#Add sources to the project
set(SOURCES_PREFIX ${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src)
list(APPEND SOS_SOURCELIST ${SOURCES})

get_filename_component(SOS_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${SOS_NAME} CXX C)

if( ${SOS_BUILD_CONFIG} STREQUAL arm )
	set(SOS_DEFINITIONS BASELINE)
	set(SOS_CONFIG BASELINE_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS ARRAY_TEST)
	set(SOS_CONFIG ARRAY_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS BITSET_TEST)
	set(SOS_CONFIG BITSET_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS DEQUE_TEST)
	set(SOS_CONFIG DEQUE_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS FORWARD_LIST_TEST)
	set(SOS_CONFIG FORWARD_LIST_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS LIST_TEST)
	set(SOS_CONFIG LIST_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS MAP_TEST)
	set(SOS_CONFIG MAP_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS QUEUE_TEST)
	set(SOS_CONFIG QUEUE_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS SET_TEST)
	set(SOS_CONFIG SET_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS STACK_TEST)
	set(SOS_CONFIG STACK_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS UNORDERED_MAP_TEST)
	set(SOS_CONFIG UNORDERED_MAP_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS UNORDERED_SET_TEST)
	set(SOS_CONFIG UNORDERED_SET_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS VECTOR_TEST)
	set(SOS_CONFIG VECTOR_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

	set(SOS_DEFINITIONS STRING_TEST)
	set(SOS_CONFIG STRING_TEST_release)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

elseif( ${SOS_BUILD_CONFIG} STREQUAL link )
	#This will compile natively. If the program uses hardware, it can "link" to a board over USB
	set(SOS_ARCH link)
	set(SOS_CONFIG release)
	set(SOS_LIBRARIES jansson sgfx)
	include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app.cmake)
endif()
