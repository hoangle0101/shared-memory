// src/reset.c
#include "../include/shared_memory.h"

int main() {
    // Xóa Shared Memory (nếu tồn tại)
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id >= 0) {
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
        } else {
            printf("Old shared memory segment deleted.\n");
        }
    } else {
        perror("shmget (no shared memory to delete)");
    }

    // Xóa Semaphore (nếu tồn tại)
    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem != SEM_FAILED) {
        sem_close(sem);
        sem_unlink(SEM_NAME);
        printf("Old semaphore deleted.\n");
    } else {
        perror("sem_open (no semaphore to delete)");
    }

    // Tạo lại Shared Memory
    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    } else {
        printf("New shared memory segment created.\n");
    }

    // Tạo lại Semaphore
    sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    } else {
        printf("New semaphore created.\n");
    }

    printf("System reset successfully.\n");
    return 0;
}
