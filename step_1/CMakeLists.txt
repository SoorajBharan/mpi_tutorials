cmake_minimum_required(VERSION 3.10)
project("step_1")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(MPI)

add_executable(step_1 step_1.cpp)

include_directories(${MPI_CXX_INCLUDE_DIRS})

target_link_libraries(step_1 ${MPI_CXX_LIBRARIES})
