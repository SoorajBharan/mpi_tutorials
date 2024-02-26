cmake_minimum_required(VERSION 3.10)
project("step_5")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(MPI)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(
	step_5
	step_5.cpp
	display.h
	vmat_operations.h)

include_directories(${MPI_CXX_INCLUDE_DIRS})

target_link_libraries(step_5 ${MPI_CXX_LIBRARIES})
