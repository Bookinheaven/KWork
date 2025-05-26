#include <stdio.h> 
#include <unistd.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
	key_t k = ftok("f1", 65);
	int id = shmget(k, 1024, 0666|IPC_CREAT);
	char *d = (char*)shmat(id, 0, 0);
	sem_t *s = sem_open("/rw_sem", O_CREAT , 0666, 0);
	if (fork() == 0 ) {
		sem_wait(s);
		printf("Reader: %s\n", d);
	} else {
		sprintf(d, "Writer Note");
		sem_post(s);
		wait(NULL);
		shmdt(d);
		shmctl(id, IPC_RMID, NULL);
		sem_close(s);
		sem_unlink("/rw_sem");
	}
	return 0;
}
	