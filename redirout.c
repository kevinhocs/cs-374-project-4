#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]){

    if (argc < 3){
        fprintf (stderr, 
            "Usage: redirout [arg1 [arg2...]]\n");
        exit (1);
    }

    int fd = open (argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1){
        perror ("open");
        exit (1);
    }

    dup2 (fd, STDOUT_FILENO);
    close (fd);

    execvp (argv[2], &argv[2]);

    perror ("execvp failed");
    exit (1);
}