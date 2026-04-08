/*
Dans cet exercice, utilisez la fonction getchar et putchar.

Étant donné la lecture de caractères au clavier, on souhaite crypter le message introduit de la manière suivante :
•	Toute lettre est remplacée par la lettre 3 positions plus loin (exemple : a devient d, A devient D, etc.), exceptées les 3 dernières lettres qui deviennent les premières (z devient c, y devient b, x devient a, idem pour les majuscules).
•	Tout chiffre est remplacé par un espace.
•	Tout espace est remplacé par un point.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c;

    printf("Entrez un message à crypter (Ctrl+D pour terminer) :\n");

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            // Crypter les lettres minuscules
            c = ((c - 'a' + 3) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            // Crypter les lettres majuscules
            c = ((c - 'A' + 3) % 26) + 'A';
        } else if (c >= '0' && c <= '9') {
            // Remplacer les chiffres par un espace
            c = ' ';
        } else if (c == ' ') {
            // Remplacer les espaces par un point
            c = '.';
        }
        putchar(c);
    }

    return EXIT_SUCCESS;
}