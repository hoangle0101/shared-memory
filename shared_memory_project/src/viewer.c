#include "../include/shared_memory.h"
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        print_current_time();
        printf("[Watcher] Detected change in shared memory.\n");
    }
}

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    char *shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    printf("[Watcher] Watching for changes in shared memory...\n");

    signal(SIGUSR1, signal_handler);

    // Giả lập theo dõi liên tục
    char prev_content[SHM_SIZE];
    strncpy(prev_content, shared_memory, SHM_SIZE);

    while (1) {
        if (strncmp(prev_content, shared_memory, SHM_SIZE) != 0) {
            strncpy(prev_content, shared_memory, SHM_SIZE);
            kill(0, SIGUSR1); // Gửi tín hiệu đến các tiến trình trong nhóm
        }
        sleep(1);
    }

    shmdt(shared_memory);
    return 0;
}
