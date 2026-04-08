#include <stdio.h>
#include <stdlib.h>

#define MAX_STARS 10
#define FILENAME_SIZE 30

int main(void) {
    char buffer[MAX_STARS + 1];
    char fileName [FILENAME_MAX];
    FILE *stars;

    printf("Entrez le nom du fichier de sortie : ");
    scanf("%s", fileName);
    
    stars = fopen(fileName, "w");

    if (stars == NULL) {
        printf("ENOENT\n");
        return EXIT_FAILURE;
    }

    /*for (int i = 0; i < 10; i++) {
        for(int j = 0; j < i + 1; j++) {
            fprintf(stars, "*");
        }
        fprintf(stars, "\n");
    }*/

    for (int i = 0; i < MAX_STARS; i++) {
        for(int j = 0; j < i + 1; j++) {
            buffer[j] = '*';
        }
        buffer[i] = '\n';
        buffer[i + 1] = '\0';
        fprintf(stars, "%s", buffer);
    }

    fclose(stars);

    return EXIT_SUCCESS;
}
