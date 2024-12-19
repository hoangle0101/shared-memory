#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <fcntl.h>
#include <time.h>
#include "../include/shared_memory.h"

// Hàm hiển thị thời gian hiện tại
// void print_current_time() {
//     time_t now = time(NULL);
//     struct tm *t = localtime(&now);
//     printf("[%02d:%02d:%02d] ", t->tm_hour, t->tm_min, t->tm_sec);
// }

int main() {
    // Kiểm tra shared memory
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id < 0) {
        perror("shmget");
        printf("Shared memory chưa được tạo.\n");
        exit(1);
    }
    printf("Shared memory ID: %d\n", shm_id);

    // Lấy thông tin về shared memory
    struct shmid_ds shm_info;
    if (shmctl(shm_id, IPC_STAT, &shm_info) == -1) {
        perror("shmctl");
        exit(1);
    }
    printf("Shared memory size: %ld bytes\n", shm_info.shm_segsz);
    printf("Last attach time: %s", ctime(&shm_info.shm_atime));
    printf("Last detach time: %s", ctime(&shm_info.shm_dtime));
    printf("Creator PID: %d\n", shm_info.shm_cpid);
    printf("Last operator PID: %d\n", shm_info.shm_lpid);
    printf("Number of current attaches: %ld\n", shm_info.shm_nattch);

    // Kết nối vào shared memory để xem nội dung
    char *shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(1);
    }
    printf("Shared memory content: \"%s\"\n", shared_memory);
    shmdt(shared_memory);

    // Kiểm tra semaphore
    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        printf("Semaphore chưa được tạo.\n");
        exit(1);
    } else {
        int sem_value;
        sem_getvalue(sem, &sem_value);
        printf("Semaphore value: %d\n", sem_value);
        sem_close(sem);
    }

    printf("\nTổng quan: Shared memory và semaphore đang hoạt động bình thường.\n");
    return 0;
}
