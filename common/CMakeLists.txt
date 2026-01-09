# Common static library
add_library(common STATIC
    # Source files will be added here
)

# Include directories for common headers
target_include_directories(common PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
