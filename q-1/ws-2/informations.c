/*
Écrivez (dans la fonction principale) les conditions qui correspondent aux propositions suivantes (en choisissant des noms de variables adéquats) :
•	L’âge est positif et inférieur à 18.
•	Le sexe est soit 'M', soit 'F'.
•	L’année est bissextile.

Si vous ne connaissez pas les propriétés d’une année bissextile, allez chercher sur le Net, mais ne commencez pas à recopier n’importe quoi !

Complétez ce fichier source pour qu’il demande et récupère l’âge et le sexe de l’utilisateur, et qu’il indique, après chaque obtention, si ces informations sont valides au moyen des conditions que vous avez écrites ci-avant. 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int age;
    char sexe;
    int annee;

    printf("Entrez votre âge : ");
    scanf("%d", &age);
    if (age > 0 && age < 18) {
        printf("Âge valide.\n");
    } else {
        printf("Âge invalide.\n");
    }
    // or: printf("%s\n", (age > 0 && age < 18) ? "Âge valide." : "Âge invalide.");

    printf("Entrez votre sexe (M/F) : ");
    scanf(" %c", &sexe);
    if (sexe == 'M' || sexe == 'F') {
        printf("Sexe valide.\n");
    } else {
        printf("Sexe invalide.\n");
    }
    // or: printf("%s\n", (sexe == 'M' || sexe == 'F') ? "Sexe valide." : "Sexe invalide.");

    printf("Entrez une année : ");
    scanf("%d", &annee);
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        printf("L'année %d est bissextile.\n", annee);
    } else {
        printf("L'année %d n'est pas bissextile.\n", annee);
    }
    // or (horrible à lire) :
    // printf("L'année %d %s bissextile.\n", annee, ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) ? "est" : "n'est pas");

    return EXIT_SUCCESS;
}