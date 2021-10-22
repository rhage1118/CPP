
add_library(parts SHARED)
target_include_directories(parts PRIVATE include)

target_sources(parts
    PRIVATE src/Tire.cpp
    PRIVATE src/Wheel.cpp
    PRIVATE include/Tire.hpp
    PRIVATE include/Wheel.hpp
)

install(TARGETS parts)
