#include <stdio.h>
#include <stdlib.h>

#define MAX_STARS 10
#define FILENAME_SIZE 30

int main(void) {
    char fileName [FILENAME_MAX];
    int num;
    FILE *output;

    printf("Entrez le nom du fichier de sortie : ");
    scanf("%s", fileName);
    
    output = fopen(fileName, "w");

    if (output == NULL) {
        printf("ENOENT\n");
        return EXIT_FAILURE;
    }


    for (int i = 1; i <= MAX_STARS; i++) {
        for(int j = 1; j <= i + 1; j++) {
            fprintf(output, "Le double de %d est %d.\n", i, j);
        }
    }

    fclose(output);

    return EXIT_SUCCESS;
}
