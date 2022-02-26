
add_library(cpp20 SHARED)

#target_include_directories(cpp20
#    PRIVATE "/opt/local/include/libcxx/v1/"
#)

#target_link_directories(cpp20 PRIVATE /opt/local/lib/libcxx/)
#target_link_libraries(cpp20 PUBLIC c++)

target_sources(cpp20
    PRIVATE cpp20.cpp
)

set_source_files_properties(cpp20.cpp
    PROPERTIES
        COMPILE_FLAGS "-fmodules -fmodules-ts -fmodule-name=cpp20"
)

#-Xclang -emit-module-interface -o cpp20.pcm

