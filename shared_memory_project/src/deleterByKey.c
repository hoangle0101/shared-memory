#include "../include/shared_memory.h"

void list_queue_contents(SharedQueue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current queue contents:\n");
    for (int i = 0; i < queue->size; i++) {
        int real_index = (queue->front + i) % QUEUE_CAPACITY;
        printf("  [%d]: %s\n", i, queue->queue[real_index]);
    }
}

void dequeue_by_index(SharedQueue *queue, int index) {
    if (queue->size == 0) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    if (index < 0 || index >= queue->size) {
        printf("Invalid index. Please provide a valid index between 0 and %d.\n", queue->size - 1);
        return;
    }

    int real_index = (queue->front + index) % QUEUE_CAPACITY;
    printf("Message removed from queue: %s\n", queue->queue[real_index]);

    // Shift elements after the removed element
    for (int i = real_index; i != queue->rear; i = (i + 1) % QUEUE_CAPACITY) {
        int next = (i + 1) % QUEUE_CAPACITY;
        strncpy(queue->queue[i], queue->queue[next], SHM_SIZE);
    }

    // Update rear and size
    queue->rear = (queue->rear - 1 + QUEUE_CAPACITY) % QUEUE_CAPACITY;
    queue->size--;
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

    // List queue contents
    list_queue_contents(queue);

    // Prompt user for index to delete
    if (queue->size > 0) {
        int index;
        printf("Enter the index of the message to remove: ");
        scanf("%d", &index);

        dequeue_by_index(queue, index);
    }

    shmdt(queue);
    return 0;
}
