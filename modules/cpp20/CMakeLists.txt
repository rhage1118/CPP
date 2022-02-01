file(GLOB SRC *.cpp)

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})

set_source_files_properties(cpp20 PROPERTIES COMPILE_FLAGS -fmodule-file=cpp20=cpp20.cpp.o)

set_source_files_properties(cpp20_impl.cpp PROPERTIES COMPILE_FLAGS "-fprebuilt-module-path=./CMakeFiles/cpp20.dir/ -fmodule-file=cpp20.cpp.o.d ")

add_library(cpp20 MODULE ${SRC})
target_compile_options(cpp20 PUBLIC -fmodules -fmodules-ts)


