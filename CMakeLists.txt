cmake_minimum_required(VERSION 3.21)

project(magic_proof VERSION 1.0)

SET(CMAKE_CXX_STANDARD 20)		    # use c++ 20
SET(CMAKE_CXX_STANDARD_REQUIRED ON)	# make it a requirement of compiler
SET(CMAKE_CXX_EXTENSIONS OFF)		# don't use compiler extensions, just CXX standard

file(GLOB SRC *.cpp *.hpp)

# find_package(GSL REQUIRED)

# add the executable
add_executable(${PROJECT_NAME} "${SRC}")
add_dependencies(${PROJECT_NAME} parts)
target_include_directories(${PROJECT_NAME} PUBLIC parts/include)
target_link_libraries(${PROJECT_NAME} PUBLIC GSL::gsl parts)

add_subdirectory(parts)

