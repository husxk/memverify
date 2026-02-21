#include <common/file_reader.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

#define SV_SOCK_PATH "/tmp/sock"
#define BUF_SIZE 128

void sim_file()
{
    filepack_t *n = filepack_create_write("test.txt");
    write_in(n, "made");
    filepack_delete(n);
}

int main()
{
    sim_file();  

    filepack_t *r = filepack_create_read("test.txt");

    struct sockaddr_un addr;
    ssize_t numRead;
    char buf[BUF_SIZE];

    int sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    printf("Client socket fd = %d\n", sfd);

    if (sfd == -1) 
    {
        filepack_delete(r);
        return -1;
    }
    
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

    if (connect(sfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1) 
    {
        close(sfd);
        filepack_delete(r);
        return -1;
    }

    while ((numRead = read(ptr_to_num(r), buf, BUF_SIZE)) > 0) 
    {
        if (write(sfd, buf, numRead) != numRead) 
        {
            close(sfd);
            filepack_delete(r);
            return -1;
        }
    }

    if (numRead == -1) 
    {
        close(sfd);
        filepack_delete(r);
        return -1;
    }

    exit(EXIT_SUCCESS);
}
