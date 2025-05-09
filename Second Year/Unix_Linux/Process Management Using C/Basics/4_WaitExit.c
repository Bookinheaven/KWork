#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == 0 ){
		printf("Child running..\n");
		exit(0);
	} else {
		wait(NULL);
		printf("Child process finished.\n");
	}
	return 0;
}
