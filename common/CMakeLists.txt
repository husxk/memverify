cmake_minimum_required(VERSION 3.10)
project(common)

# Common static library
add_library(common STATIC
    src/file_reader.c
)

# Include directories for common headers
target_include_directories(common PUBLIC
    include
)
