#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
	int fd;
	char *fifo = "/tmp/myfifo";
	mkfifo(fifo, 0666);
	if (fork() == 0) {
		fd = open(fifo, O_WRONLY);
		char str1[] = "Hi from Child";
		write(fd, str1, sizeof(str1));
		close(fd);
	} else {
		char buffer[20];
		fd = open(fifo, O_RDONLY);
		read(fd, buffer, sizeof(buffer));
		printf("Parent received: %s\n", buffer);
		close(fd);
	}
	return 0;
}

