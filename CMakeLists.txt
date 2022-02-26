cmake_minimum_required(VERSION 3.16)

project(magic_proof VERSION 1.0)

SET(CMAKE_CXX_STANDARD 20)		    # use c++ 20
SET(CMAKE_CXX_STANDARD_REQUIRED ON)	# make it a requirement of compiler
SET(CMAKE_CXX_EXTENSIONS OFF)		# don't use compiler extensions, just CXX standard

# eg: -DEXTRA=-fsanitize=address
message(NOTICE "-- EXTRA: `${EXTRA}`")
if (DEFINED "EXTRA")
    add_compile_options(${EXTRA})
    add_link_options(${EXTRA})
endif()

# find_package(GSL REQUIRED)

add_executable(magic_proof)

target_include_directories(magic_proof
    PUBLIC parts/include
    PUBLIC thread/include
    #PUBLIC GSL::gsl parts
)
target_link_libraries(magic_proof
    PUBLIC parts
    PUBLIC thread
)

target_sources(magic_proof
    PRIVATE DerivedVehicle.hpp
    PRIVATE Vehicle.hpp
    PRIVATE DerivedVehicle.cpp
    PRIVATE Vehicle.cpp
    PRIVATE main.cpp
)

#set_source_files_properties(main.cpp PROPERTIES COMPILE_FLAGS  "-fmodules -fmodules-ts  -fprebuilt-module-path=cpp20/CMakeFiles/cpp20.dir/ -fimplicit-modules -fimplicit-module-maps")

add_dependencies(magic_proof
    parts
    thread
#    cpp20
)

add_subdirectory(parts)
add_subdirectory(thread)
#add_subdirectory(cpp20)

install(TARGETS magic_proof)
