// src/view_queue.c
#include "../include/shared_memory.h"

void view_queue(SharedQueue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents:\n");
    for (int i = queue->front; i != queue->rear; i = (i + 1) % QUEUE_CAPACITY) {
        printf("Message: %s\n", queue->queue[i]);
    }
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

    view_queue(queue);

    shmdt(queue);
    return 0;
}
