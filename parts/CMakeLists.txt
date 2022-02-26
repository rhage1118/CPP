
add_library(parts SHARED)
target_include_directories(parts PUBLIC include)
#target_link_libraries(parts c++)

target_sources(parts
    PRIVATE
        src/Tire.cpp
        src/Wheel.cpp
    
        include/Tire.hpp
        include/Wheel.hpp
)

install(TARGETS parts)
