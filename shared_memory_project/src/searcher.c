// src/searcher.c
#include "../include/shared_memory.h"

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

    printf("Enter a keyword to search: ");
    char keyword[100];
    scanf("%s", keyword);

    if (strstr(shared_memory, keyword)) {
        printf("Keyword '%s' found in shared memory.\n", keyword);
    } else {
        printf("Keyword '%s' not found in shared memory.\n", keyword);
    }

    shmdt(shared_memory);
    return 0;
}
