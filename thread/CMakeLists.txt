file(GLOB SRC src/*.cpp include/*.hpp)

set_source_files_properties(src/Runner.cpp PROPERTIES COMPILE_FLAGS "-nostdinc++")

add_library(thread SHARED ${SRC})
target_include_directories(thread PUBLIC include)

target_include_directories(thread PRIVATE BEFORE "/opt/local/include/libcxx/v1")
target_link_directories(thread PRIVATE /opt/local/lib/libcxx)
