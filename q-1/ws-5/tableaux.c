#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, c;
    printf("Section DA\n");

    /* Demander les 4 nombres d'une adresse IP et les mémoriser */
    int ip[4];
    for (i = 0; i < 4; ++i) {
        int val;

        do {
            printf("Entrez le %d%s octet de l'adresse IP (0-255) : ", i + 1, (i == 0) ? "er" : "ème");
            scanf("%d", &val);

            if (val < 0 || val > 255)
                printf("Valeur hors plage, réessayez.\n");
        } while (val < 0 || val > 255);
        ip[i] = val;
    }
    printf("Adresse IP saisie : %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);

    /* Déterminer le taux de réussite moyen du bloc 1 et l'afficher */
    double taux[50];
    double somme = 0.0;

    for (i = 0; i < 50; ++i) {
        double t;

        do {
            printf("Taux de réussite de l'étudiant %d (0-100) : ", i + 1);
            scanf("%lf", &t);

            if (t < 0.0 || t > 100.0)
                printf("Valeur hors plage, réessayez.\n");
        } while (t < 0.0 || t > 100.0);
        taux[i] = t;
        somme += t;
    }

    double moyenne = somme / 50.0;

    printf("Taux de réussite moyen du bloc 1 : %.2f%%\n", moyenne);

    return EXIT_SUCCESS;
}