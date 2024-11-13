cmake_minimum_required(VERSION 3.10)
project(Synth VERSION 1.0)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES
    src/synth.cpp
    src/basetypes.cpp
)

add_library(${CMAKE_PROJECT_NAME} SHARED ${SOURCES})

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "synth"
    PREFIX ""
)

if(WIN32)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE EXPORTS)
endif()

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

# target_link_libraries(${CMAKE_PROJECT_NAME} SomeOtherLibrary)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    if(CMAKE_BUILD_TOOL STREQUAL "Release")
        add_compile_options(-O2 -flto)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-Wall -Wextra -pedantic)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if(CMAKE_BUILD_TOOL STREQUAL "Release")
        add_compile_options(/O2 /GL /LTCG)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(/W3 /permissive)
    endif()
endif()

if (UNIX AND NOT APPLE)
    install(TARGETS ${CMAKE_PROJECT_NAME}
        LIBRARY DESTINATION lib  # For .so file
    )

    install(DIRECTORY include/
        DESTINATION include  # For headers
    )

elseif(APPLE)
    install(TARGETS ${CMAKE_PROJECT_NAME}
        LIBRARY DESTINATION lib  # For .dylib file
    )

    install(DIRECTORY include/
        DESTINATION include  # For headers
    )

endif()
