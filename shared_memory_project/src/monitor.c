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
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget failed. Possible reasons: incorrect size, key conflict.");
        exit(1);
    }

    // Kết nối tới shared memory
    char *shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Kết nối semaphore để đảm bảo thread-safe
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open failed. Ensure initializer ran successfully.");
        exit(1);
    }

    printf("Monitoring shared memory and queue...\n");

    // Dùng để theo dõi nội dung shared memory và trạng thái queue
    char last_content[SHM_SIZE] = {0};          
    SharedQueue last_queue_state = {0};         
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
        sleep(1); // Đợi 1 giây trước khi kiểm tra lại
    }

    // Giải phóng semaphore và shared memory
    sem_close(sem);
    shmdt(shared_memory);

    // Nếu cần, xóa semaphore khi kết thúc chương trình
    sem_unlink(SEM_NAME);

    return 0;
}
