cmake_minimum_required(VERSION 3.5)
project(spider)

if (UNIX)
	set (CMAKE_CXX_FLAGS "-m32 -w -fpermissive")
endif()

if (MSVC)
	if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
		message(FATAL_ERROR "Please switch to x32 build.")
	endif()
endif()

file(GLOB SRC_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})
