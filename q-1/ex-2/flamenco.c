/*
Un centre culturel organise un atelier « Flamenco » dont le tarif annuel est de 
•	100 euros pour les enfants de 6 à 11 ans,
•	120 euros pour les jeunes de 12 à 18 ans,
•	160 euros pour les personnes de plus de 18 ans.
Écrivez le programme qui détermine et affiche le prix à payer par une personne qui s’inscrit à l’atelier et dont on obtient l’âge.
Remarque : il faut 6 ans minimum pour s’inscrire et si ce n’est pas le cas, votre programme doit afficher un message le signalant.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int age;
    int tarif;

    printf("Âge : ");
    scanf("%d", &age);

    if (age < 6) {
        printf("Âge minimum requis : 6 ans.\n");
    } else {
        if (age <= 11) {
            tarif = 100;
        } else if (age <= 18) {
            tarif = 120;
        } else {
            tarif = 160;
        }

        printf("Tarif annuel : %d euros.\n", tarif);
    }

    return EXIT_SUCCESS;
}
