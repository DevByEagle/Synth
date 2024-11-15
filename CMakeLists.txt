cmake_minimum_required(VERSION 3.15)
project(Synth)

# Directory for easier includes
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Sets compiler flags and language standard
include(CompilerFlags)

add_subdirectory(src Synth)

enable_testing()