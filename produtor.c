#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#include "util.h"

int main(int argc, char *argv[]){
    int fd, nbytes;
    char str[20];

    if(access(PIPE_NAME, F_OK) != 0){
        printf("[ERRO] FIFO '%s' nao existe", PIPE_NAME);
    }
    printf("Verifiquei FIFO... '%s'\n", PIPE_NAME);
    fd = open(PIPE_NAME, O_WRONLY);
    printf("Abri FIFO (WRITE)... '%s'\n", PIPE_NAME);
    do{
        scanf("%s", str);
        nbytes = read(fd, str, sizeof(str) -1);
        if(nbytes > 0){
            str[nbytes] = '\0';
            printf("Escrevi...'%s (%d bytes)'\n", str, nbytes);
        }
    }while (strcmp(str, "fim") != 0);
    close(fd);
    unlink(PIPE_NAME);
}

