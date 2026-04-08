#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char line[200];

    FILE *recipe = fopen("cocktail.txt", "r");

    if (recipe == NULL) {
        printf("ENOENT\n");
        return EXIT_FAILURE;
    }

    printf("INGREDIENTS:\n");
    for (int i = 0; i < 5; i++) {
        fgets(line, 200, recipe);
        printf("* %s", line);
    }

    fgets(line, 200, recipe);
    printf("\n");

    printf("RECETTE:\n");
    for (int i = 0; i < 4; i++) {
        fgets(line, 200, recipe);
        printf("%s", line);
    }
    printf("\n");

    fclose(recipe);

    return EXIT_SUCCESS;
}
