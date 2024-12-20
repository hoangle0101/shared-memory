#include "../include/shared_memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>

#define SEM_NAME "/shared_memory_sem"

void edit_message(SharedQueue *queue, int index, const char *new_message) {
    if (index < 0 || index >= queue->size) {
        printf("Invalid index. Operation aborted.\n");
        return;
    }

    int actual_index = (queue->front + index) % QUEUE_CAPACITY;
    strncpy(queue->queue[actual_index], new_message, SHM_SIZE - 1);
    queue->queue[actual_index][SHM_SIZE - 1] = '\0'; // Đảm bảo kết thúc chuỗi
    printf("Message at index %d updated to: %s\n", index, queue->queue[actual_index]);
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

    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    sem_wait(sem);

    if (queue->size == 0) {
        printf("Queue is empty. Nothing to edit.\n");
        sem_post(sem);
        sem_close(sem);
        shmdt(queue);
        return 0;
    }

    printf("Current queue:\n");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % QUEUE_CAPACITY;
        printf("[%d] %s\n", i, queue->queue[index]);
    }

    int edit_index;
    printf("Enter the index of the message to edit: ");
    scanf("%d", &edit_index);
    getchar(); // Xóa newline khỏi bộ đệm

    char new_message[SHM_SIZE];
    printf("Enter the new message: ");
    fgets(new_message, SHM_SIZE, stdin);
    new_message[strcspn(new_message, "\n")] = '\0';

    edit_message(queue, edit_index, new_message);

    sem_post(sem);
    sem_close(sem);
    shmdt(queue);

    return 0;
}
