#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* args[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", args[0]);
        return EXIT_FAILURE;
    }

    FILE* file = fopen(args[1], "r");

    if (file == NULL) {
        printf("ENOENT\n");
        return EXIT_FAILURE;
    }

    char line[100];
    int line_number = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("\033[0;32m%d \033[0m%s", line_number, line);
        line_number++;
    }
    fclose(file);
    
    return EXIT_SUCCESS;
}
