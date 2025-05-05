#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *args[] = {"du", "../../" ,"-h", NULL};
    
    if (fork() == 0) {
        // Child executes ls -l
        execvp(args[0], args);
        perror("exec failed");  // Only reached if exec fails
        _exit(1);  // Use _exit() in child after exec fails
    } else {
        wait(NULL);  // Parent waits for child
    }
    return 0;
}
