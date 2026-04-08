#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

#define MAX_LINE_SIZE 500

int main(int argc, char* args[]) {
    if (argc < 4) {
        printf("Usage: %s <file> <keyword> <destination>\n", args[0]);
        return EXIT_FAILURE;
    }


    FILE *streamIn;
    FILE *streamOutt;
    bool isStdout = false;

    streamIn = fopen(args[1], "r");

    if (strcmp(args[3], "stdout") == 0) {
        streamOutt = stdout;
        isStdout = true;
    } else {
        streamOutt = fopen(args[3], "w");
    }

    if (streamIn == NULL) {
        printf("ENOENT: %s\n", args[1]);
        exit(EXIT_FAILURE);
    }

    if (streamOutt == NULL) {
        printf("ENOENT: %s\n", args[3]);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_SIZE];
    int lineNumber = 1;

    while (fgets(line, MAX_LINE_SIZE, streamIn) != NULL) {
        if (strstr(line, args[2]) != NULL) {
            if (!isStdout) {
                fprintf(streamOutt, "%d: %s", lineNumber, line);
            } else {
                printf("\033[32m%s:%d:\033[0m %s", args[1], lineNumber, line);
            }
        }
        lineNumber++;
    }

    if (!isStdout) {
        printf("Results written to %s\n", args[3]);
    }

    fclose(streamIn);
    fclose(streamOutt);

    return EXIT_SUCCESS;
}
