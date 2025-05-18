#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == 0) {
		printf("Child exits.\n");		
	} else {
		sleep(10);
		printf("Parent Running\n");
	}
	return 0;
}