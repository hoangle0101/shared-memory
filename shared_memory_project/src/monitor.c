// src/monitor.c
#include "../include/shared_memory.h"
#include <sys/shm.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SEM_NAME "/shared_memory_sem"



void print_queue(SharedQueue *queue) {
    printf("Queue state:\n");
    if (queue->size == 0) {
        printf("  Queue is empty.\n");
    } else {
        for (int i = 0; i < queue->size; i++) {
            int index = (queue->front + i) % QUEUE_CAPACITY;
            printf("  [%d]: %s\n", i, queue->queue[index]);
        }
    }
    printf("------------------------\n");
}

int main() {
    // Kết nối tới shared memory
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    char *shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Kết nối semaphore để đảm bảo thread-safe
    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    printf("Monitoring shared memory and queue...\n");

    char last_content[SHM_SIZE] = {0};          // Dùng để theo dõi nội dung shared memory
    SharedQueue last_queue_state = {0};         // Dùng để theo dõi trạng thái queue
    SharedQueue *queue = (SharedQueue *)shared_memory; // Trỏ tới hàng đợi trong shared memory

    while (1) {
        sem_wait(sem); // Đảm bảo thread-safe khi truy cập shared memory

        // Kiểm tra thay đổi trong nội dung shared memory
        if (strcmp(last_content, shared_memory) != 0) {
            printf("Shared memory updated:\n  %s\n", shared_memory);
            strncpy(last_content, shared_memory, SHM_SIZE);
        }

        // Kiểm tra thay đổi trong queue
        if (memcmp(&last_queue_state, queue, sizeof(SharedQueue)) != 0) {
            printf("Queue updated:\n");
            print_queue(queue);
            memcpy(&last_queue_state, queue, sizeof(SharedQueue)); // Cập nhật trạng thái cuối cùng
        }

        sem_post(sem); // Giải phóng semaphore
        sleep(1);
    }

    // Giải phóng shared memory
    shmdt(shared_memory);

    return 0;
}
