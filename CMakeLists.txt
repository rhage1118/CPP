cmake_minimum_required(VERSION 3.21)

project(magic_proof VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



# add the executable
add_executable(${PROJECT_NAME} Vehicle.cpp main.cpp)
