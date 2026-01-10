#include <iostream>
#include <cstdio>

#include "common/file_reader.hpp"

void file_reader::open(const std::string& filepath)
{
    printf("hello world %s\n", filepath.c_str());
}
