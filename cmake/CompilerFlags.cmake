if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(-O2 -flto)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-Wall -Wextra -pedantic)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(/O2 /GL /LTCG)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(/W3 /permissive)
    endif()
endif()