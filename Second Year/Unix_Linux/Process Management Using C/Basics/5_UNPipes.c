#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(0);
    } else if (pid == 0) {
        close(fd[0]);
        char msg[] = "Hello from child process!";
        write(fd[1], msg, sizeof(msg));       
    } else {
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Received from child: %s\n", buffer);
        wait(NULL);
    }
    return 0;
}