/*
On désire écrire un programme qui permet de valider un mot de passe numérique (uniquement composé de chiffres).
Ce mot de passe est fixé dans votre programme, soit via une variable, soit via une constante symbolique. 
L'utilisateur a droit à 5 essais pour se connecter. Vous pouvez également utiliser une constante symbolique pour cette valeur.
Si le mot de passe est correct, le message "Connexion en cours…" est affiché et le programme est terminé, sinon, il peut recommencer.
À chaque erreur, le message "Erreur…réessayez…" est affiché.
S'il ne parvient pas à se connecter au bout des 5 essais, le message "Consultez l'administrateur de votre réseau…" est affiché.
*/
#include <stdio.h>
#include <stdlib.h>

#define NB_ESSAIS_MAX 5
#define MOT_DE_PASSE 1234

int main(void) {
    int saisie;
    int essais;

    printf("Entrez le mot de passe numérique : ");
    scanf("%d", &saisie);
    essais = 1;


    while (essais < NB_ESSAIS_MAX && saisie != MOT_DE_PASSE) {
        printf("Erreur...réessayez...\n");
        printf("Entrez le mot de passe numérique : ");
        scanf("%d", &saisie);
        essais++;
    }

    if (essais == NB_ESSAIS_MAX) {
        printf("Consultez l'administrateur de votre réseau...\n");
    } else {
        printf("Connexion en cours...\n");
    }

    return EXIT_SUCCESS;
}