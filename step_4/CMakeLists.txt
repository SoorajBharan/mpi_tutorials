cmake_minimum_required(VERSION 3.10)
project("step_4")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(MPI)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(
	step_4
	step_4.cpp
	display.h
	send_and_receive.h)

include_directories(${MPI_CXX_INCLUDE_DIRS})

target_link_libraries(step_4 ${MPI_CXX_LIBRARIES})
