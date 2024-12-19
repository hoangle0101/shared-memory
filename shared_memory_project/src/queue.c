// src/enqueue.c
#include "../include/shared_memory.h"

void enqueue(SharedQueue *queue, const char *message) {
    if (queue->size == QUEUE_CAPACITY) {
        printf("Queue is full. Cannot add new message.\n");
        return;
    }
    strncpy(queue->queue[queue->rear], message, SHM_SIZE);
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->size++;
}

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    SharedQueue *queue = (SharedQueue *)shmat(shm_id, NULL, 0);
    if (queue == (SharedQueue *)-1) {
        perror("shmat");
        exit(1);
    }

    char message[SHM_SIZE];
    printf("Enter a message to add to the queue: ");
    fgets(message, SHM_SIZE, stdin);

    enqueue(queue, message);
    printf("Message added to queue: %s\n", message);

    shmdt(queue);
    return 0;
}
