#include <common/file_reader.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

#define BACKLOG 1
#define SV_SOCK_PATH "/tmp/sock"
#define BUF_SIZE 128

int main()
{
    struct sockaddr_un addr;
    
    int sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    printf("Server socket fd = %d\n", sfd);

    if (sfd == -1) 
    {
        perror("socket");
        return -1;
    }

    if (strlen(SV_SOCK_PATH) > sizeof(addr.sun_path) - 1) {
        perror("too long socket path");
        close(sfd);
        return -1;
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

    unlink("/tmp/sock");

    if (bind(sfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1) 
    {
        perror("bind");
        close(sfd);
        return -1;
    }

    if (listen(sfd, BACKLOG) == -1) 
    {
        perror("listen");
        close(sfd);
        return -1;
    }

    ssize_t numRead;
    char buf[BUF_SIZE];

    printf("Waiting to accept a connection...\n");
        
    int cfd = accept(sfd, NULL, NULL);
    printf("Accepted socket fd = %d\n", cfd);

    while ((numRead = read(cfd, buf, BUF_SIZE)) > 0) 
    {
        if (write(STDOUT_FILENO, buf, numRead) != numRead) 
        {
            perror("write");
            close(sfd);
            close(cfd);
            return -1;
        }
    }

    if (numRead == -1) 
    {
        perror("read");
        close(sfd);
        close(cfd);
        return -1;
    }

    if (close(cfd) == -1) 
    {
        perror("close");
        return -1;
    }
}
