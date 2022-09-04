
add_library(thread SHARED)
target_include_directories(thread
    PRIVATE include
)
target_link_libraries(thread c++)

target_sources(thread
    PRIVATE include/Runner.hpp
    PRIVATE src/Runner.cpp
)

#set_source_files_properties(src/Runner.cpp PROPERTIES COMPILE_FLAGS "-nostdinc++")

install(TARGETS thread)
