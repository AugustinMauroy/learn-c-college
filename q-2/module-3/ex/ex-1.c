#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum famille Famille;
enum famille {
    COEUR,
    CARREAU,
    TREFLE,
    PIQUE
};

typedef struct carte Carte;
struct carte {
	Famille famille;
	int valeur;
};

bool estRouge(Carte carte) {
    return carte.famille == COEUR || carte.famille == CARREAU;
}

void afficheFamille(Carte carte) {
    const char *nomsFamilles[] = {
        "coeur", "carreau", "trèfle", "pique"
    };
    printf("%s", nomsFamilles[carte.famille]);
}

void afficheCarte(Carte carte) {
    if (estRouge(carte))
        printf("\033[31m"); // Code ANSI pour rouge

    switch (carte.valeur) {
        case 1:
            printf("As");
            break;
        case 11:
            printf("Valet");
            break;
        case 12:
            printf("Dame");
            break;
        case 13:
            printf("Roi");
            break;
        default:
            printf("%d", carte.valeur);
    }
    printf(" de ");
    afficheFamille(carte);
    printf("\n");

    printf("\033[0m"); // Code ANSI pour réinitialiser la couleur
}

/*
•	Les as sont les cartes les plus fortes.
•	Si deux cartes ont la même valeur, la famille détermine qui est la plus forte :
    o	Cœur est la famille la plus forte ;
    o	Carreau est une famille plus forte que Trèfle et Pique ;
    o	Trèfle est plus fort que Pique.
•	Si les valeurs sont différentes, la carte qui a la plus grande valeur est la plus forte.
*/
bool estPlusForte(Carte carte1, Carte carte2) {
    if (carte1.valeur == carte2.valeur) {
        return carte1.famille < carte2.famille; // Plus la famille est forte, plus son indice est bas
    }

    return carte1.valeur == 1 || carte2.valeur == 1 ? carte1.valeur == 1 : carte1.valeur > carte2.valeur;
} 

int indicePlusForteCarte(Carte pileCartes[], int taille) {
    int indicePlusForte = 0;

    for (int i = 1; i < taille; i++) {
        if (estPlusForte(pileCartes[i], pileCartes[indicePlusForte])) {
            indicePlusForte = i;
        }
    }

    return indicePlusForte;
}

int main(void) {
    Carte valetPique = { PIQUE, 11 };
    Carte asCoeur = { COEUR, 1 };
    Carte pileCartes[] = {
        {COEUR, 3},
        {CARREAU, 7},
        {TREFLE, 1},
        {PIQUE, 13},
        {COEUR, 10},
        {CARREAU, 5},
        {TREFLE, 9},
        {PIQUE, 2},
        {COEUR, 12},
        {CARREAU, 8}
    };
    Carte mains[7][5] = {
        { {COEUR, 1}, {CARREAU, 3}, {TREFLE, 5}, {PIQUE, 7}, {COEUR, 9} },
        { {CARREAU, 2}, {TREFLE, 4}, {PIQUE, 6}, {COEUR, 8}, {CARREAU, 10} },
        { {TREFLE, 11}, {PIQUE, 12}, {COEUR, 13}, {CARREAU, 1}, {TREFLE, 3} },
        { {PIQUE, 5}, {COEUR, 7}, {CARREAU, 9}, {TREFLE, 11}, {PIQUE, 13} },
        { {COEUR, 2}, {CARREAU, 4}, {TREFLE, 6}, {PIQUE, 8}, {COEUR, 10} },
        { {CARREAU, 3}, {TREFLE, 5}, {PIQUE, 7}, {COEUR, 9}, {CARREAU, 11} },
        { {TREFLE, 13}, {PIQUE, 1}, {COEUR, 3}, {CARREAU, 5}, {TREFLE, 7} }
    };



    printf("Le valet de pique est-il rouge ? %s\n", estRouge(valetPique) ? "Oui" : "Non");
    printf("L'as de coeur est-il rouge ? %s\n", estRouge(asCoeur) ? "Oui" : "Non");

    for (int i = 0; i < sizeof(pileCartes) / sizeof(Carte); i++) {
        afficheCarte(pileCartes[i]);
    }

    int indicePlusForte = indicePlusForteCarte(pileCartes, sizeof(pileCartes) / sizeof(Carte));
    printf("La carte la plus forte est : ");
    afficheCarte(pileCartes[indicePlusForte]);

    for (int i = 0; i < sizeof(mains) / sizeof(mains[0]); i++) {
        int indicePlusForteMain = indicePlusForteCarte(mains[i], sizeof(mains[i]) / sizeof(Carte));
        printf("MAIN %d\n  ", i + 1);
        afficheCarte(mains[i][indicePlusForteMain]);
        printf("\n");
    }

    
    return EXIT_SUCCESS;
}
