cmake_minimum_required(VERSION 3.10)
project(Synth VERSION 1.0 LANGUAGES CXX)

# Output directory configuration
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Source directory and source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB SOURCES "${SRC_DIR}/*.cpp")

# Create a shared library
add_library(${CMAKE_PROJECT_NAME} SHARED ${SOURCES})
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "synth"
    PREFIX ""
)

# Platform-specific compile definitions
if(WIN32)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE EXPORTS)
endif()

# Include directories
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Uncomment to link additional libraries
# target_link_libraries(${CMAKE_PROJECT_NAME} SomeOtherLibrary)

# Compiler-specific options
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

# Installation for Unix/Linux and macOS
if(UNIX AND NOT APPLE)
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