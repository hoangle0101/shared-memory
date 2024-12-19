// include/shared_memory.h
#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define SHM_KEY 12345
#define SHM_SIZE 1024
#define SEM_NAME "/shm_semaphore"
#define QUEUE_CAPACITY 10  // Số lượng phần tử tối đa trong hàng đợi
typedef struct {
    int front;
    int rear;
    int size;
    char queue[QUEUE_CAPACITY][SHM_SIZE];  // Mỗi phần tử là một chuỗi ký tự
} SharedQueue;

// Hàm hiển thị thời gian hiện tại dưới dạng chuỗi
void print_current_time() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("[%02d:%02d:%02d] ", tm.tm_hour, tm.tm_min, tm.tm_sec);
}
void enqueue(SharedQueue *queue, const char *message);
void view_queue(SharedQueue *queue);
void dequeue(SharedQueue *queue);
void log_activity(const char *activity);

#endif
