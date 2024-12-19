// src/initializer.c
#include "../include/shared_memory.h"

int main() {
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }
    printf("Shared memory segment created with ID: %d\n", shm_id);

    char *shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(1);
    }
    memset(shared_memory, 0, SHM_SIZE);
    shmdt(shared_memory);

    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }
    printf("Semaphore initialized.\n");
    sem_close(sem);

    return 0;
}