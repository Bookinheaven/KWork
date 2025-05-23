#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

#define CHUNK_SIZE 100

int main() {
	int fd, pipefd[2];
	pid_t pid;
	char buffer[CHUNK_SIZE];
	ssize_t bytesRead;
	
	fd = open("data.txt", O_RDONLY);
	if (fd < 0) {
		perror("open");
		exit(0);
	}
	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(0);
	}
	pid = fork();
	if(pid > 0) {
		close(pipefd[0]);
		while ((bytesRead = read(fd, buffer, CHUNK_SIZE)) > 0 ) {
			write(pipefd[1], buffer, bytesRead);
		}
		close(fd);
		close(pipefd[1]);
		wait(NULL);
	} else {
		close(pipefd[1]);
		while ((bytesRead = read(pipefd[0], buffer, CHUNK_SIZE)) > 0 ) {
			buffer[bytesRead] = '\0';
			printf("Chunk received: \n%s\n", buffer);
			printf("----------\n");
			
		}
		close(pipefd[0]);
	}
		return 0;
}
