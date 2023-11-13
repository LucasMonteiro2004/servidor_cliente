#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#include "util.h"


int main(int argc, char *argv[]) {
    int fd, nbytes;
    char str[20];

    mkfifo(PIPE_NAME, 0644);
    printf("Criei FIFO... \n");
    fd = open(PIPE_NAME, O_RDWR);
    printf("Abri FIFO (READ)... \n");
    do{
        nbytes = read(fd, str, sizeof(str) -1);
        if(nbytes > 0){
            str[nbytes] = '\0';
            printf("Li...'%s (%d bytes)'\n", str, nbytes);

        }
    }while (nbytes > 0);
    close(fd);
    printf("fechei FIFO... \n");
    unlink(PIPE_NAME);
    printf("Removi FIFO... \n");

    return 0;
}
