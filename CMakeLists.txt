cmake_minimum_required(VERSION 3.10)
project(memverify)

# Set C standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(common)
add_subdirectory(host)
add_subdirectory(target)
