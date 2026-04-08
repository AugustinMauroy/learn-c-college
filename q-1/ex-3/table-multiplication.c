#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nombtre;

    printf("Nombre :");
    scanf("%d", &nombtre);

    for (int i = 1; i < 10; i++) {
        printf("%d x %d = %D\n", i, nombtre, i * nombtre);
    }
    

    return 0;
}