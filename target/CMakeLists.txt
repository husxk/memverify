cmake_minimum_required(VERSION 3.10)
project(target)

# Target executable
add_executable(target
    main.cpp
)

# Link against common library
target_link_libraries(target
    common
)
