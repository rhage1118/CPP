file(GLOB SRC src/*.cpp include/*.hpp)

add_library(parts SHARED ${SRC})
target_include_directories(parts PUBLIC include)
