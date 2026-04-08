#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    do {
        printf("Nombre (0 pour terminer) : ");
        scanf("%d", &n);
    
        if (n != 0) {
            for (int i = 1; i <= 10; i++) {
                printf("%2d x %2d = %3d\n", i, n, i * n);
            }
            printf("\n");
        }
    } while (n != 0);

    return EXIT_SUCCESS;
}