cmake_minimum_required(VERSION 3.0)
project(spider)

set (CMAKE_CXX_FLAGS "-m32 -w -fpermissive")

file(GLOB SRC_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})
