# Target executable
add_executable(target
    main.cpp
)

# Link against common library
target_link_libraries(target
    common
)
