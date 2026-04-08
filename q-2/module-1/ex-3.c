#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
1.	Écrivez une fonction qui reçoit un tableau de chaînes de caractères ainsi que le nombre de chaînes de caractères qu’il contient et les affiche.
Ajoutez à votre fonction principal un appel en utilisant le tableau prenoms défini ci-dessus (mais notez qu’il ne contient que 6 prénoms pour le moment).
2.	Par quoi faut-il compléter le code suivant pour qu’il affiche correctement la lettre g  du prénom augustine puis le prénom etienne ? Assûrez-vous de bien comprendre à quoi correspondent les écritures prenoms[0][2] et prenoms[3].
```c
printf("…", prenoms[0][2]);
printf("…", prenoms[3]);
```
3.	Dans la fonction principale, ajoutez une instruction demandant à l’utilisateur d’entrer un 7e prénom, qui sera placé à la fin du tableau prenoms. Réalisez deux versions : une version avec scanf et une version avec gets. C’est une bonne occasion pour vérifier que vous vous souvenez des différences entre les deux.
4.	Écrivez une fonction qui reçoit un tableau de chaînes de caractères ainsi que le nombre de chaînes de caractères et qui affiche chacune des chaînes de caractères et sa taille.
5.	Écrivez une fonction qui reçoit un tableau de chaînes de caractères, le nombre de chaînes de caractères ainsi qu’un caractère et qui affiche les chaînes qui contiennent le caractère en question. 
Dans la fonction principale, demandez un caractère à l’utilisateur puis utilisez-le pour faire appel à la fonction.
*/

#define TAILLE 25

void displayStrings(char strings[][TAILLE], int numStrings) {
    for (int i = 0; i < numStrings; i++) {
        printf("%s\n", strings[i]);
    }
}

void displayStringsWithSize(char strings[][TAILLE], int numStrings) {
    for (int i = 0; i < numStrings; i++) {
        printf("%s - taille: %lu\n", strings[i], strlen(strings[i]));
    }
}

void displayStringsContainingChar(char strings[][TAILLE], int numStrings, char c) {    
    printf("Strings containing '%c':\n", c);
    
    for (int i = 0; i < numStrings; i++) {
        int j = 0;

        while (strings[i][j] != '\0' && strings[i][j] != c) {
            j++;
        }
        
        if (strings[i][j] == c) {
            printf("%s\n", strings[i]);
        }
    }
}

int main(void) {
    char prenoms[7][TAILLE] = {
        "augustine",
        "bernard",
        "cunegonde",
        "etienne",
        "fernande",
        "gulliver"
    };
    char caractereRecherche;

    // Partie 1 et 2: Afficher les prénoms
    printf("=== Partie 1: Affichage des prenoms ===");
    printf("\n");
    displayStrings(prenoms, 6);
    
    // Partie 2: Démonstration d'accès aux caractères
    printf("\n=== Partie 2: Demonstration ===");
    printf("\n");
    printf("La lettre 'g' du prenom 'augustine' (prenoms[0][2]): %c\n", prenoms[0][2]);
    printf("Le prenom 'etienne' (prenoms[3]): %s\n", prenoms[3]);
    
    // Partie 3: Ajouter un 7e prénom
    printf("\n=== Partie 3: Ajout d'un 7e prenom ===");
    printf("\n");
    printf("Entrez un 7e prenom (scanf): ");
    scanf("%24s", prenoms[6]);  // Limite à 24 caractères pour éviter le débordement
    getchar();
    
    printf("Entrez un 7e prenom (gets - non recommande): ");
    gets(prenoms[6]);
    
    // Partie 4: Afficher les prénoms avec leur taille
    printf("\n=== Partie 4: Affichage des prenoms avec leur taille ===");
    printf("\n");
    displayStringsWithSize(prenoms, 7);
    
    // Partie 5: Rechercher les prénoms contenant un caractère
    printf("\n=== Partie 5: Recherche par caractere ===");
    printf("\n");
    
    
    printf("Entrez un caractere a rechercher : ");
    scanf("%c", &caractereRecherche);
    displayStringsContainingChar(prenoms, 7, caractereRecherche);

    return 0;
}
