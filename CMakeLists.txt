cmake_minimum_required(VERSION 3.10)
project(memverify)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(common)
add_subdirectory(host)
add_subdirectory(target)
