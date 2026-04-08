#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define LG_TEXTE 100

void miseEnMajuscules(char *texte) {
    char *ptr = texte;
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

void capitalisationInitiales(char *texte) {
    char *ptr = texte;
    bool estDebutMot = true;

    while (*ptr != '\0') {
        if (estDebutMot && isalpha(*ptr)) {
            *ptr = toupper(*ptr);
            estDebutMot = false;
        } else if (*ptr == ' ' || *ptr == '-') {
            estDebutMot = true;
        } else {
            *ptr = tolower(*ptr);
        }
        ptr++;
    }
}

int main(void) {
    char texte[LG_TEXTE];

    printf("Entrez un texte : ");
    fgets(texte, LG_TEXTE, stdin);
    printf("\n"); // fgets consume le \n du buffer

    printf("Texte en majuscules :\n");
    miseEnMajuscules(texte);
    printf("%s", texte);

    printf("Texte avec capitalisation des initiales :\n");
    capitalisationInitiales(texte);
    printf("%s", texte);

    return EXIT_SUCCESS;
}
