#include <stdlib.h>
#include <stdio.h>

/*
Un carré magique est une grille carrée de nombres où chaque ligne et chaque colonne possède la même somme. C’est par exemple le cas de la grille ci-dessous, où la somme des nombres sur n’importe quelle ligne ou n’importe quelle colonne vaut 65.
```
17	24	1	8	15
23	5	7	14	16
4	6	13	20	22
10	12	19	21	3
11	18	25	2	9
```
Un carré magique peut être de n’importe quelle taille mais, dans le cadre de cet exercice, on ne considérera que les carrés magiques de taille 5 x 5 (pensez donc à définir une constante symbolique).

Dans un nouveau programme, créez les fonctions suivantes :
1.	une fonction qui reçoit un tableau à 2 dimensions et un indice de ligne et qui renvoie la somme des valeurs qui se trouvent sur cette ligne ;
2.	une fonction qui reçoit un tableau à 2 dimensions et un indice de colonne et qui renvoie la somme des valeurs qui se trouvent sur cette colonne ;
3.	une fonction qui reçoit un tableau carré à 2 dimensions et affiche s’il s’agit bien d’un carré magique. Dans le cas où le tableau est un carré magique, la fonction affichera le total qu’on obtient (pour chaque ligne et chaque colonne). Dans le cas contraire, la fonction citera deux lignes ou colonnes qui n’ont pas la même somme.

**Remarque:**
Dans la vérification d’un carré magique, si vous vous rendez compte que la somme de la 2e ligne n’est pas la même que la somme de la 1re ligne, vous n’allez pas vous amuser à calculer les sommes des lignes suivantes juste pour le plaisir… faites en sorte que votre programme n’effectue pas non plus de calculs inutiles !
*/

#define SQUARE_SIZE 5

// Fonction 1 : calcule la somme des valeurs d'une ligne
int sumLine(int square[SQUARE_SIZE][SQUARE_SIZE], int line) {
    int sum = 0;

    for (int i = 0; i < SQUARE_SIZE; i++) {
        sum += square[line][i];
    }

    return sum;
}

// Fonction 2 : calcule la somme des valeurs d'une colonne
int sumColumn(int square[SQUARE_SIZE][SQUARE_SIZE], int col) {
    int sum = 0;

    for (int i = 0; i < SQUARE_SIZE; i++) {
        sum += square[i][col];
    }

    return sum;
}

// Fonction 3 : affiche si c'est un carré magique
void verifyMagicSquare(int square[SQUARE_SIZE][SQUARE_SIZE]) {
    int i;
    int magicSum = sumLine(square, 0);
    
    /*for (int i = 1; i < SQUARE_SIZE; i++) {
        if (sumLine(square, i) != magicSum) {
            printf("Ce n'est pas un carré magique.\n");
            printf("La ligne 1 a une somme de %d, mais la ligne %d a une somme de %d.\n",magicSum, i + 1, sumLine(square, i));
            return;
        }
    }

    for (int i = 0; i < SQUARE_SIZE; i++) {
        if (sumColumn(square, i) != magicSum) {
            printf("Ce n'est pas un carré magique.\n");
            printf("La colonne 1 a une somme de %d, mais la colonne %d a une somme de %d.\n", magicSum, i + 1, sumColumn(square, i));
            return;
        }
    }*/
    i = 0;
    while (i < SQUARE_SIZE && sumLine(square, i) == magicSum) {
        i++;
    }
    if (i < SQUARE_SIZE) {
        printf("Ce n'est pas un carré magique.\n");
        printf("La ligne 1 a une somme de %d, mais la ligne %d a une somme de %d.\n",magicSum, i + 1, sumLine(square, i));
        return;
    }

    i = 0;
    while (i < SQUARE_SIZE && sumColumn(square, i) == magicSum) {
        i++;
    }
    if (i < SQUARE_SIZE) {
        printf("Ce n'est pas un carré magique.\n");
        printf("La colonne 1 a une somme de %d, mais la colonne %d a une somme de %d.\n", magicSum, i + 1, sumColumn(square, i));
        return;
    }
    
    printf("C'est un carré magique ! La somme de chaque ligne et colonne est %d.\n", magicSum);
}

int main(void) {
    int carreMagique1[SQUARE_SIZE][SQUARE_SIZE] = {
    {17, 24,  1,  8, 15},
    {23,  5,  7, 14, 16},
    { 4,  6, 13, 20, 22},
    {10, 12, 19, 21,  3},
    {11, 18, 25,  2,  9}
    };
    int carreMagique2[SQUARE_SIZE][SQUARE_SIZE] = {
        { 1,  2,  3, 16, 20},
        { 4,  5, 14,  6, 13},
        { 7, 12,  8,  9,  6},
        {15, 10, 11,  4,  2},
        {15, 13,  6,  7,  1}
    };
    int carreMagique3[SQUARE_SIZE][SQUARE_SIZE] = {
        {15, 10, 10, 10, 26},
        {14, 15, 10, 10, 22},
        {14, 15, 11, 10, 21},
        {14, 15, 12, 10, 20},
        {14, 16, 13, 10, 18}
    };

    printf("=== Carré magique 1 ===\n");
    verifyMagicSquare(carreMagique1);
    
    printf("\n=== Carré magique 2 ===\n");
    verifyMagicSquare(carreMagique2);
    
    printf("\n=== Carré magique 3 ===\n");
    verifyMagicSquare(carreMagique3);
    
    return 0;
}