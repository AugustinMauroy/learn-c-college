#include <stdio.h>
#include <stdlib.h>

double pourcentage(int part, int total) {
    if (total == 0) return 0.0;

    return ((double)part / (double)total) * 100.0;
}

int main(void) {
    double resultat = pourcentage(11, 15);

    printf("Le pourcentage est de : %.2f%%\n", resultat);

    return EXIT_SUCCESS;
}
