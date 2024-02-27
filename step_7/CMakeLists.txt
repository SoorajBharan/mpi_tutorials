cmake_minimum_required(VERSION 3.10)
project("step_7")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(MPI)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(
	step_7
	step_7.cpp
	display.h
	vmat_operations.h)

include_directories(${MPI_CXX_INCLUDE_DIRS})

target_link_libraries(step_7 ${MPI_CXX_LIBRARIES})
