#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int jour;
	int mois;
	int annee;
} Date;

void afficheDate (Date d) {
    char nomMois[][10] = {
        "janvier",
        "fevrier",
        "mars",
        "avril",
        "mai",
        "juin",
        "juillet",
        "aout",
        "septembre",
        "octobre",
        "novembre",
        "decembre"
    };

    printf("%02d/%s/%04d\n", d.jour, nomMois[d.mois - 1], d.annee);
}

Date dateObtenue(void) {
    Date d;

    printf("Entrez une date");
    do {
        printf("Jour (1-31): ");
        scanf("%d", &d.jour);
    } while (d.jour < 1 || d.jour > 31);

    do {
        printf("Mois (1-12): ");
        scanf("%d", &d.mois);
    } while (d.mois < 1 || d.mois > 12);

    printf("Annee (1900-2100): ");
    scanf("%d", &d.annee);

    return d;
}

int main(void) {
    Date date1 = {15, 8, 2021};
    Date date2;

    printf("Date 1 : ");
    afficheDate(date1);

    date2 = dateObtenue();
    printf("Date 2 : ");
    afficheDate(date2);

    return EXIT_SUCCESS;
}