#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum caracteristiqueMaison CaracteristiqueMaison;
enum caracteristiqueMaison {
    A_GARAGE = 0b00000001,
    A_JARDIN = 0b00000010,
    A_ANNEXE = 0b00000100,
    EST_PROCHE_AUTOROUTE = 0b00001000,
    EST_RECENTE = 0b00010000,
    EST_DANS_ZONE_1 = 0b00100000,
    EST_DANS_ZONE_2 = 0b01000000,
    EST_DANS_ZONE_3 = 0b10000000
};

void afficheAtouts(CaracteristiqueMaison maison) {
    if (maison & A_GARAGE|A_JARDIN|A_ANNEXE|EST_PROCHE_AUTOROUTE|EST_RECENTE) {
        printf("avec ");
        if (maison & A_GARAGE) {
            printf("garage ");
        }
        if (maison & A_JARDIN) {
            printf("jardin ");
        }
        if (maison & A_ANNEXE) {
            printf("annexe ");
        }
        if (maison & EST_PROCHE_AUTOROUTE) {
            printf("proche de l'autoroute ");
        }
        if (maison & EST_RECENTE) {
            printf("recemment construite/renovee ");
        }
    } else {
        printf("sans atouts particuliers");
    }
}

void afficheAvantages(CaracteristiqueMaison maison) {
    if (maison & A_GARAGE) {
        printf("- garage\n");
    }
    if (maison & A_JARDIN) {
        printf("- jardin\n");
    }
    if (maison & A_ANNEXE) {
        printf("- annexe\n");
    }
    if (maison & EST_PROCHE_AUTOROUTE) {
        printf("- proche de l'autoroute\n");
    }
    if (maison & EST_RECENTE) {
        printf("- recemment construite/renovee\n");
    }
    if (maison & EST_DANS_ZONE_1) {
        printf("- en zone 1\n");
    }
    if (maison & EST_DANS_ZONE_2) {
        printf("- en zone 2\n");
    }
    if (maison & EST_DANS_ZONE_3) {
        printf("- en zone 3\n");
    }

}

void afficheMaison(CaracteristiqueMaison maison) {
    if (maison & EST_DANS_ZONE_1) {
        printf("Maison en zone 1 ");
    } else if (maison & EST_DANS_ZONE_2) {
        printf("Maison en zone 2 ");
    } else if (maison & EST_DANS_ZONE_3) {
        printf("Maison en zone 3 ");
    } else {
        printf("Maison sans zone ");
    }
    afficheAtouts(maison);
    printf("\n");
    afficheAvantages(maison);
}

int main(void) {
    CaracteristiqueMaison maison1 = 0b01011111;
    CaracteristiqueMaison maison2 = 0b10001000;
    CaracteristiqueMaison maison3 = 0b00110010;

    afficheMaison(maison1);
    printf("\n");
    afficheMaison(maison2);
    printf("\n");
    afficheMaison(maison3);

    return EXIT_SUCCESS;
}
