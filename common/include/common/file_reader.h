#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    FILE *f;
    const char *fname;
} filepack_t;

filepack_t* filepack_create_read(const char *fname);

filepack_t* filepack_create_write(const char *new_file);

void filepack_delete(filepack_t *r);

void print(filepack_t *r);

int ptr_to_num(filepack_t *r);

void write_in(filepack_t *r, char* info);

#endif
