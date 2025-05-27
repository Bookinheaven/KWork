#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
	key_t key = ftok("d1", 65);
	int id = shmget(key, 1024, 0666 | IPC_CREAT);
	int *address = (int*)shmat(id, 0, 0);
	sem_t *s = sem_open("pc_sem", O_CREAT, 0666, 0);
	if (fork() == 0) {
		for (int i=0; i<5; i++) {
			sem_wait(s);
			printf("Consumed: %i\n", *address);	
		}
		shmdt(address);
	} else {
		for (int i = 0; i<5; i++) {
            *address = i;
			printf("Produced: %d\n", i);
			sem_post(s);
			sleep(1);
		}
		wait(NULL);
		shmdt(address);
		shmctl(id, IPC_RMID, NULL);
		sem_close(s);
		sem_unlink("pc_sem");
	}
	return 0;
	
}
