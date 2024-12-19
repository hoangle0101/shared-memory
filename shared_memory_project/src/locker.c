// src/locker.c
#include "../include/shared_memory.h"

int main() {
    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    printf("Locking shared memory...\n");
    sem_wait(sem);
    printf("Shared memory locked. Press Enter to unlock.\n");
    getchar();
    sem_post(sem);
    printf("Shared memory unlocked.\n");

    sem_close(sem);
    return 0;
}
