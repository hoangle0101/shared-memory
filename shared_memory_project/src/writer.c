#include "../include/shared_memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>

#define SEM_NAME "/shared_memory_sem"

int main() {
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    SharedQueue *queue = (SharedQueue *)shmat(shm_id, NULL, 0);
    if (queue == (SharedQueue *)-1) {
        perror("shmat");
        exit(1);
    }

    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    sem_wait(sem);

    // Ghi vào buffer tạm trong shared memory
    printf("Enter message (writer): ");
    fgets(queue->buffer, SHM_SIZE, stdin);
    printf("Message written to shared memory buffer: %s\n", queue->buffer);

    sem_post(sem);

    sem_close(sem);
    shmdt(queue);

    return 0;
}
