#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child (PID=%d) is running.\n", getpid());
    } else {
        printf("Parent (PID=%d) is about to terminate.\n", getpid());
        kill(getpid(), SIGKILL);  
    }
    return 0; 
}