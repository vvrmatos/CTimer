#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Author: Spaceman Y2K38

void clear_screen() {
    // Clears the terminal screen
    system("clear");
}

int parse_arguments(int argc, char *argv[]) {
    int seconds = 30; // default value

    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], "--set-sec=", 10) == 0) {
            seconds = atoi(argv[i] + 10);
            if (seconds <= 0) {
                fprintf(stderr, "Invalid time value. Using default of 30 seconds.\n");
                seconds = 30;
            }
        }
    }

    return seconds;
}

int main(int argc, char *argv[]) {
    int seconds = parse_arguments(argc, argv);

    while (1) {
        for (int i = seconds; i >= 0; i--) {
            clear_screen();
            printf("Countdown: %d seconds\n", i);
            sleep(1);
        }
    }

    return 0;
}

