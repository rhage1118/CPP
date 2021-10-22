
add_library(thread SHARED)
target_include_directories(thread PRIVATE include)

target_sources(thread
    PRIVATE include/Runner.hpp
    PRIVATE src/Runner.cpp
)

install(TARGETS thread)
