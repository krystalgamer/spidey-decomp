cmake_minimum_required(VERSION 3.5)
project(spider LANGUAGES CXX)

message ("Will create project for decomp! ${CMAKE_SYSTEM_PROCESSOR}")


if (MSVC)
	message("Creating Windows project")
	if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
		message(FATAL_ERROR "Please switch to x32 build.")
	endif()
else()
	string (APPEND CMAKE_CXX_FLAGS " -w -fpermissive -std=c++11")
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		message("Creating for G++")
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		message("Creating for Clang++")
		string (APPEND CMAKE_CXX_FLAGS " -fms-extensions -Wno-address-of-temporary")
	else()
		message(FATAL_ERROR "Could not detect compiler")
	endif()

	if (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
		string (APPEND CMAKE_CXX_FLAGS  " -m32")
		set (LIBZ_NAME ${CMAKE_SOURCE_DIR}/lib/libz_x86.a)
	elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
		set (LIBZ_NAME ${CMAKE_SOURCE_DIR}/lib/libz_aarch64.a)
	else()
		message(FATAL_ERROR "Could not detect architecture")
	endif()
endif()



file(GLOB SRC_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

if (UNIX)
	target_link_libraries(${PROJECT_NAME} ${LIBZ_NAME})
elseif(WIN32)
	target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/safesehzlib.lib winmm.lib dinput8.lib dxguid.lib dsound.lib ddraw.lib)
endif ()
