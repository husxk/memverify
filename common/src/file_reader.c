#include "common/file_reader.h"
#include <stdio.h>
#include <stdlib.h>

filepack_t* filepack_create_read(const char *fname)
{
    filepack_t *r = malloc(sizeof(filepack_t));
    
    r->fname = fname;
    r->f = fopen(fname, "r");

    if (r->f == NULL) {
        perror("Couldnt open file");
        return NULL;
    }
    return r;
}

filepack_t* filepack_create_write(const char *new_file)
{
    filepack_t *r = malloc(sizeof(filepack_t));

    r->fname = new_file;
    r->f = fopen(new_file, "w");

    if (!r->f) {
        perror("Couldnt open file");
        return NULL;
    }
    return r;
}

void filepack_delete(filepack_t *r)
{
    if (!r) return;

    if (r->f) fclose(r->f);                       
    free(r);
}

void print(filepack_t *r)
{
    char buff[200];

    FILE *fp = r->f;

    while (fgets(buff, sizeof(buff), fp) != NULL) {
        printf("%s", buff);
    }
}

void write(filepack_t *r, char* info)
{
    fprintf(r->f, "%s\n", info);
}
