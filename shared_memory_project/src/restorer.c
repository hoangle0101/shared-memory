// src/restorer.c
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

    char backup_file[100];
    printf("Enter backup file name to restore: ");
    scanf("%s", backup_file);

    FILE *file = fopen(backup_file, "r");
    if (file == NULL) {
        perror("fopen");
        shmdt(shared_memory);
        exit(1);
    }

    fread(shared_memory, 1, SHM_SIZE, file);
    fclose(file);

    printf("Shared memory restored from file: %s\n", backup_file);

    shmdt(shared_memory);
    return 0;
}
