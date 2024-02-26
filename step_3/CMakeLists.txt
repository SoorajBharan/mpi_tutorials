cmake_minimum_required(VERSION 3.10)
project("step_3")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(MPI)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(
	step_3
	step_3.cpp
	display.h
	round_robin.h)

include_directories(${MPI_CXX_INCLUDE_DIRS})

target_link_libraries(step_3 ${MPI_CXX_LIBRARIES})
