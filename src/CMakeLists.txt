project(Synth C)
set(PROJECT_VERSION 1.0.0)

option(BUILD_SHARED_LIBS "Build a shared libaray" OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(synth_public_headers
    synth.h
    typing.h
    )

file(GLOB SOURCES "*.cpp" "*.c")

if (BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCES} ${synth_public_headers})
    set_target_properties(${PROJECT_NAME} PROPERTIES
                      PUBLIC_HEADER "${synth_public_headers}"
                      VERSION ${PROJECT_VERSION}
                      PREFIX ""
                      )
else()
    add_library(${PROJECT_NAME} ${SOURCES} ${synth_public_headers})
    set_target_properties(${PROJECT_NAME} PROPERTIES
                          PUBLIC_HEADER "${synth_public_headers}"
                          VERSION ${PROJECT_VERSION}
                          OUTPUT_NAME "synth"
                          )        
endif()

file(COPY ${synth_public_headers} DESTINATION "include")

include(CPack)

enable_testing()