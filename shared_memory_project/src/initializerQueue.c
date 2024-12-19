#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>

#define SHM_KEY 12345
#define SEM_NAME "/shared_memory_sem"
#define QUEUE_CAPACITY 10
#define SHM_SIZE 1024

typedef struct {
    char queue[QUEUE_CAPACITY][SHM_SIZE];
    int front, rear, size;
} SharedQueue;

int main() {
    // Tạo shared memory
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Gắn shared memory
    SharedQueue *queue = (SharedQueue *)shmat(shm_id, NULL, 0);
    if (queue == (SharedQueue *)-1) {
        perror("shmat");
        exit(1);
    }

    // Khởi tạo hàng đợi
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    memset(queue->queue, 0, sizeof(queue->queue));

    // Tạo semaphore
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    printf("Shared memory and semaphore initialized successfully.\n");

    // Đóng semaphore và detach shared memory
    sem_close(sem);
    shmdt(queue);

    return 0;
}
