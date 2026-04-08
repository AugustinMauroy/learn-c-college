#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 100

int main(void) {
    char product[MAX_LINE_SIZE];
    double price = 0.0;
    double total = 0.0;

    FILE *courses = fopen("courses.txt", "r");

    if (courses == NULL) {
        printf("ENOENT\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 12; i = i + 2) {
        fscanf(courses, "%s %lf", product, &price);
        printf("%s : %.2f\n", product, price);
        total += price;
    }

    printf("==================\n");
    printf("Total : %.2f\n", total);

    fclose(courses);

    return EXIT_SUCCESS;
}
