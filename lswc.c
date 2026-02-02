#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[]) {

int fd[2];
if (pipe(fd) == -1) {
    perror("pipe");
    exit(1);
}

pid_t pid = fork();
if (pid == -1) {
    perror("fork");
    exit(1);
}

if (pid == 0) {
    // Child process
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);

    execlp("wc", "wc", "-l", NULL);
    perror("wc failed");
    exit(1);

} else {
    // Parent process

    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close (fd[1]);

    if (argc > 1) {
        execlp("ls", "ls", "-1a", argv[1], NULL);
    } else {
        execlp("ls", "ls", "-1a", NULL);
    }
    perror("ls failed");
    exit(1);
    }
}