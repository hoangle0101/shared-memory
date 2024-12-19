// src/writer.c
#include "../include/shared_memory.h"

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    char *shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    sem_wait(sem);
    print_current_time();
    printf("Enter message: ");
    fgets(shared_memory, SHM_SIZE, stdin);
    print_current_time();
    printf("Message written to shared memory: %s\n", shared_memory);
    sem_post(sem);

    sem_close(sem);
    shmdt(shared_memory);

    return 0;
}