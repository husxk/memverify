# Host executable
add_executable(host
    main.cpp
)

# Link against common library
target_link_libraries(host
    common
)
