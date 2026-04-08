#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum couleur Couleur;

enum couleur {
    ROUGE,
    ORANGE,
    JAUNE,
    VERT,
    BLEU,
    VIOLET
};

void afficheCouleurs(void) {
    printf("Rouge : %d\n", ROUGE);
    printf("Orange: %d\n", ORANGE);
    printf("Jaune: %d\n", JAUNE);
    printf("Vert: %d\n", VERT);
    printf("Bleu: %d\n", BLEU);
    printf("Violet: %d\n", VIOLET);
}

void afficheNomCouleur(Couleur couleur) {
    const char *nomsCouleurs[] = {
        "rouge", "orange", "jaune", "vert", "bleu", "violet"
    };
    printf("%s", nomsCouleurs[couleur]);
}

bool estDansListe(Couleur couleur, Couleur liste[], int tailleListe) {
    int i = 0;
    while (i < tailleListe && liste[i] != couleur)
        i++;
    return i < tailleListe;
}

int main(void) {
    Couleur couleurCiel = BLEU;
    Couleur couleurHerbe;
    Couleur couleursSoleil[] = { ROUGE, ORANGE, JAUNE };
    Couleur couleurPreferee = VERT;

    couleurHerbe = VERT;

    if (couleurCiel == ROUGE)
        printf("Panique !\n");

    if (estDansListe(couleurPreferee, couleursSoleil, 3))
        printf("Votre couleur préférée est dans les couleurs du soleil.\n");
    else
        printf("Votre couleur préférée n'est pas dans les couleurs du soleil.\n");

    printf("Votre couleur préférée est : ");
    afficheNomCouleur(couleurPreferee);
    printf("\n");

    printf("Couleurs du soleil : ");
    for (int i = 0; i < 3; i++) {
        afficheNomCouleur(couleursSoleil[i]);
        printf(" ");
    }
    printf("\n");

    afficheCouleurs();

    return EXIT_SUCCESS;
}
