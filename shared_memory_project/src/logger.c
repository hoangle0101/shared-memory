// src/logger.c
#include "../include/shared_memory.h"

void log_activity(const char *activity) {
    FILE *log_file = fopen("system_log.txt", "a");
    if (log_file == NULL) {
        perror("Unable to open log file");
        exit(1);
    }

    print_current_time();
    fprintf(log_file, "%s - %s\n", __TIME__, activity);
    fclose(log_file);
}

int main() {
    // Ví dụ sử dụng logger
    log_activity("System initialized");
    log_activity("Message added to queue");
    log_activity("Message removed from queue");

    return 0;
}
