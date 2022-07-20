cmake_minimum_required (VERSION 2.8.11)
project (msglogger)

add_library(msglogger src/msglogger.c)
target_include_directories(msglogger PRIVATE include/)

set_target_properties(msglogger
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
