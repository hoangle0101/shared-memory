// src/backup.c
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
    printf("Enter backup file name: ");
    scanf("%s", backup_file);

    FILE *file = fopen(backup_file, "w");
    if (file == NULL) {
        perror("fopen");
        shmdt(shared_memory);
        exit(1);
    }

    fprintf(file, "%s", shared_memory);
    fclose(file);

    printf("Shared memory backed up to file: %s\n", backup_file);

    shmdt(shared_memory);
    return 0;
}
