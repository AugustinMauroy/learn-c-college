#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int entiers[] = {12, 23, 34, 45, 56, 67, 78};
    int *pEntier = entiers;

    printf("%d\n", *pEntier);
    printf("%d\n", *++pEntier);
    printf("%d\n", *(pEntier+3));
    printf("%d\n", *pEntier--);
    printf("%d\n", --*pEntier); 

    int multiples100[] = {100, 200, 300, 400, 500, 600};
    int *pMultiples100 = multiples100 + 2;

    printf("%d\n", *pMultiples100);
    printf("%p\n", pMultiples100);
    printf("%d\n", *++pMultiples100);
    printf("%d\n", *(pMultiples100 - 1));
    printf("%d\n", *pMultiples100 + 70);
    printf("%d\n", --*pMultiples100);
    printf("%d\n", *--pMultiples100);

    char option[] = "Informatique";
    char *pOption = option;
    char caract;

    caract = *(pOption + 3);
    printf("%c\n", caract);
    caract = *++pOption;
    printf("%c\n", caract);
    caract = *pOption++;
    printf("%c\n", caract);
    caract = ++(*pOption);
    printf("%c\n", caract);
    puts(option);


    return EXIT_SUCCESS;
}
