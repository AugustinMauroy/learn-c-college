#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tab[] = {12, 7, 9, 20, 33, 42, 55, 60, 71, 84};

    for (int i = 0; i < 10; i++) {
        if (tab[i] % 2 == 0) {
            printf("%d ", tab[i]);
        }
    }
    printf("\n");
    

    return EXIT_SUCCESS;
}