#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum couleur Couleur;
typedef enum jour Jour;

enum couleur {
    ROUGE,
    ORANGE,
    JAUNE,
    VERT,
    BLEU,
    VIOLET
};

enum jour {
    DIMANCHE,
    LUNDI,
    MARDI,
    MERCREDI,
    JEUDI,
    VENDREDI,
    SAMEDI
};

typedef struct {
    int heure;
    int minutes;
} Heure;

typedef struct {
    Jour jour;
    Heure heure;
    Couleur couleur;
} PlageHoraire;

void afficheNomJour(Jour jour) {
    const char *nomsJours[] = {
        "DIMANCHE", "LUNDI", "MARDI", "MERCREDI", "JEUDI", "VENDREDI", "SAMEDI"
    };
    printf("%s", nomsJours[jour]);
}

void afficheNomCouleur(Couleur couleur) {
    const char *nomsCouleurs[] = {
        "rouge", "orange", "jaune", "vert", "bleu", "violet"
    };
    printf("%s", nomsCouleurs[couleur]);
}

void affichePlageHoraire(PlageHoraire plage) {
    afficheNomJour(plage.jour);
    printf(" à %02dh%02d (", plage.heure.heure, plage.heure.minutes);
    afficheNomCouleur(plage.couleur);
    printf(")\n");
}

bool estPlageValide(PlageHoraire plage) {
    return (plage.jour != SAMEDI && plage.jour != DIMANCHE) && (plage.heure.heure >= 8 && plage.heure.heure <= 16);
}

void changeCouleur(Couleur couleur) {
    const char *codesCouleurs[] = {
        "\033[1;31m", "\033[38;5;214m", "\033[1;33m",
        "\033[1;32m", "\033[1;34m", "\033[1;35m"
    };
    printf("%s", codesCouleurs[couleur]);
}

void reinitialiseCouleur() {
    printf("\033[1;0m");
}

int main(void) {
    PlageHoraire cours[] = {
        {DIMANCHE, {0, 0}, ROUGE}, {LUNDI, {1, 15}, ORANGE}, {MARDI, {2, 30}, JAUNE},
        {MERCREDI, {3, 45}, VERT}, {JEUDI, {4, 0}, BLEU}, {VENDREDI, {5, 15}, VIOLET},
        {SAMEDI, {6, 30}, ROUGE}, {DIMANCHE, {7, 45}, ORANGE}, {LUNDI, {8, 0}, JAUNE},
        {MARDI, {9, 15}, VERT}, {MERCREDI, {10, 30}, BLEU}, {JEUDI, {11, 45}, VIOLET},
        {VENDREDI, {12, 0}, ROUGE}, {SAMEDI, {13, 15}, ORANGE}, {DIMANCHE, {14, 30}, JAUNE},
        {LUNDI, {15, 45}, VERT}, {MARDI, {16, 0}, BLEU}, {MERCREDI, {17, 15}, VIOLET},
        {JEUDI, {18, 30}, ROUGE}, {VENDREDI, {19, 45}, ORANGE}, {SAMEDI, {20, 0}, JAUNE},
        {DIMANCHE, {21, 15}, VERT}, {LUNDI, {22, 30}, BLEU}, {MARDI, {23, 45}, VIOLET},
        {MERCREDI, {0, 0}, ROUGE}, {JEUDI, {1, 15}, ORANGE}, {VENDREDI, {2, 30}, JAUNE},
        {SAMEDI, {3, 45}, VERT}, {DIMANCHE, {4, 0}, BLEU}, {LUNDI, {5, 15}, VIOLET},
        {MARDI, {6, 30}, ROUGE}, {MERCREDI, {7, 45}, ORANGE}, {JEUDI, {8, 0}, JAUNE},
        {VENDREDI, {9, 15}, VERT}, {SAMEDI, {10, 30}, BLEU}, {DIMANCHE, {11, 45}, VIOLET},
        {LUNDI, {12, 0}, ROUGE}, {MARDI, {13, 15}, ORANGE}, {MERCREDI, {14, 30}, JAUNE},
        {JEUDI, {15, 45}, VERT}, {VENDREDI, {16, 0}, BLEU}, {SAMEDI, {17, 15}, VIOLET},
        {DIMANCHE, {18, 30}, ROUGE}, {LUNDI, {19, 45}, ORANGE}, {MARDI, {20, 0}, JAUNE},
        {MERCREDI, {21, 15}, VERT}, {JEUDI, {22, 30}, BLEU}, {VENDREDI, {23, 45}, VIOLET},
        {SAMEDI, {0, 0}, ROUGE}, {DIMANCHE, {1, 15}, ORANGE}, {LUNDI, {2, 30}, JAUNE}
    };

    for (int i = 0; i < 50; i++) {
        if (estPlageValide(cours[i])) {
            changeCouleur(cours[i].couleur);
            affichePlageHoraire(cours[i]);
            reinitialiseCouleur();
        }
    }

    return EXIT_SUCCESS;
}
