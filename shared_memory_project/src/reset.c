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
    // Lấy ID của Shared Memory
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Gắn Shared Memory
    SharedQueue *queue = (SharedQueue *)shmat(shm_id, NULL, 0);
    if (queue == (SharedQueue *)-1) {
        perror("shmat");
        exit(1);
    }

    // Mở semaphore
    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        shmdt(queue);
        exit(1);
    }

    // Đợi semaphore
    sem_wait(sem);

    // Xóa nội dung của buffer
    memset(queue->buffer, 0, SHM_SIZE);
    printf("Shared memory buffer cleared.\n");

    // Giải phóng semaphore
    sem_post(sem);

    // Đóng semaphore và tách shared memory
    sem_close(sem);
    shmdt(queue);

    return 0;
}
