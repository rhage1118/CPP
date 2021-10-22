cmake_minimum_required(VERSION 3.16)

project(magic_proof VERSION 1.0)

SET(CMAKE_CXX_STANDARD 20)          # use c++ 20
SET(CMAKE_CXX_STANDARD_REQUIRED ON) # make it a requirement of compiler
SET(CMAKE_CXX_EXTENSIONS OFF)       # don't use compiler extensions, just CXX standard

# eg: -DEXTRA=-fsanitize=address
message(NOTICE "-- EXTRA: `${EXTRA}`")
if (DEFINED "EXTRA")
    add_compile_options(${EXTRA})
    add_link_options(${EXTRA})
endif()

add_executable(magic_proof)

target_include_directories(magic_proof
    PUBLIC
        parts/include
        thread/include
)
target_link_libraries(magic_proof
    PUBLIC
        parts
        thread
)

target_sources(magic_proof
    PRIVATE
        DerivedVehicle.hpp
        Vehicle.hpp
        DerivedVehicle.cpp
        Vehicle.cpp
        main.cpp
        CXXModules.cmake
        toolchain_gnu
        toolchain_llvm
)

find_package(GSL)
if(GSL_FOUND)
  message(STATUS "Found GSL: ${GSL_INCLUDE_DIRS}") # Print the include directories
  target_compile_definitions(magic_proof PUBLIC GSL_ON)
  target_include_directories(magic_proof PUBLIC ${GSL_INCLUDE_DIRS})
  target_link_libraries(magic_proof PUBLIC ${GSL_LIBRARIES}) # Link the GSL library
endif()

add_dependencies(magic_proof
    parts
    thread
)

add_subdirectory(parts)
add_subdirectory(thread)
#add_subdirectory(cpp20)

install(TARGETS magic_proof)
