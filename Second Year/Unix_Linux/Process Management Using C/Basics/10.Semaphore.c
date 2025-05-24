#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

sem_t semaphore;

int shared_resource = 0;

void *access_shared_resource(void* arg) {
	sem_wait(&semaphore);
	printf("Thread %ld is accessing the shared resource.\n", (long)arg);
	shared_resource++;
	printf("Shared reosurce value: %d\n", shared_resource);
	
	sleep(2);
	sem_post(&semaphore);
	return NULL;
}
int main() {
	pthread_t threads[5];
	int i;
	
	if (sem_init(&semaphore, 0, 1) != 0) {
		perror("sem_init failed");
		exit(1);
	}
	
	for (i = 0; i < 5; i++) {
		pthread_create(&threads[i], NULL, access_shared_resource, (void *)(long)i);
	}
	for (i = 0; i < 5; i++) {
		pthread_join(threads[i], NULL);
	}
	sem_destroy(&semaphore);
	return 0;
}
