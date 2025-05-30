#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t forks[N];

void* philosopher(void* n) {
    int id = *(int*)n;

    // Pick up forks
    sem_wait(&forks[id]);
    sem_wait(&forks[(id + 1) % N]);

    // Eating
    printf("Philosopher %d is eating\n", id);

    // Put down forks
    sem_post(&forks[id]);
    sem_post(&forks[(id + 1) % N]);

    return NULL;
}

int main() {
    pthread_t ph[N];
    int i, id[N];

    // Initialize semaphores
    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    for (i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < N; i++) {
        pthread_join(ph[i], NULL);
    }

    return 0;
}