#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 7; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }

    return EXIT_SUCCESS;
}
