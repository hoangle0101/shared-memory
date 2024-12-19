#include "../include/shared_memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>

#define SEM_NAME "/shared_memory_sem"

void enqueue(SharedQueue *queue, const char *message) {
    if (queue->size == QUEUE_CAPACITY) {
        printf("Queue is full. Cannot add new message.\n");
        return;
    }

    strncpy(queue->queue[queue->rear], message, SHM_SIZE - 1);
    queue->queue[queue->rear][SHM_SIZE - 1] = '\0'; // Đảm bảo kết thúc chuỗi
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->size++;
}

int main() {
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), 0666);
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

    char message[SHM_SIZE];
    printf("Enter a message (enqueue): ");
    fgets(message, SHM_SIZE, stdin);

    sem_wait(sem);

    // Ghi trực tiếp vào hàng đợi
    enqueue(queue, message);
    printf("Message added to queue: %s\n", message);

    sem_post(sem);

    sem_close(sem);
    shmdt(queue);

    return 0;
}
