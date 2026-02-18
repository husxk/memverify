#include <common/file_reader.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    filepack_t *n = filepack_create_write("test.txt");
    write(n, "made");
    filepack_delete(n);
    filepack_t *read = filepack_create_read("test.txt");
    print(read);
    filepack_delete(read);
    return 0;
}
