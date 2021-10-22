
include (../CXXModules.cmake)

add_module_library(cpp20 cpp20.cpp)

add_module_executable(consumer consumer.cpp)

target_link_module_libraries(consumer cpp20)


