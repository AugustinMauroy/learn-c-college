#include <stdio.h>
#include <stdlib.h>

/*
1.	Ajoutez des instructions pour demander à l’utilisateur le numéro d’un cours et le numéro d’une semaine, puis afficher le nombre d’heures correspondant.
2.	Complétez et ajoutez le code suivant, censé citer le nombre d’heures correspondant à un cours donné. Vous pouvez consulter l’exemple donné sur la capture d’écran à droite.
3.	Ajoutez les instructions nécessaires pour demander à l’utilisateur un numéro de semaine puis afficher les numéros des cours qui sont prévus cette semaine-là et le nombre d’heures pour chacun (voir exemples ci-dessous).
```
Entre le numero de la semaine: 4
Cours 1 : 2 heure(s)
Cours 3 : 2 heure(s)
Cours 4 : 2 heure(s)
```
Ajoutez les instructions nécessaires pour afficher, pour chacun des cours, le nombre total d’heures prévues à l’horaire.
```
Cours 1 : 24 heures
Cours 2 : 20 heures
Cours 3 : 20 heures
Cours 4 : 32 heures
```
5.	Ajoutez les instructions nécessaires pour afficher, pour chaque semaine, le nombre d’heures de cours prévues (tous cours confondus).
6.	Dans le code, supprimez les tailles 4 et 13 dans la déclaration. Dans le cas de tableaux simples, on pouvait ne pas les préciser quand on initialisait le tableau car le compilateur se chargeait de compter les valeurs citées. Observez ce qui se passe dans ce cas-ci.

Dans un second temps, rajoutez la dimension 13 dans la deuxième paire de crochets, mais *pas* la dimension 4. Observez le comportement du programme.
*/

/*
1.	Ajoutez cette fonction à votre programme et, dans la fonction principale, ajoutez l’appel permettant d’afficher l’horaire des cours utilisé dans les sections précédentes.
2.	Créez une fonction qui reçoit trois paramètres :
- un horaire,
- un tableau reprenant le nombre d’heures total à prévoir pour chaque cours,
- le nombre de cours,
et affiche, pour chacun des cours, une mention parmi « ok » (si le nombre d’heures total correspond au nombre d’heures prévu), « manque X heures » (s’il faut rajouter des heures de cours) ou « X heures en trop » (dans le cas contraire).

Ajoutez un appel à cette fonction dans votre fonction principale en utilisant le tableau suivant pour les heures par cours : int nbHeuresParCours[] = {24, 24, 20, 26}.
3.	Ajoutez à votre code la fonction nbOccurrences (donnée plus bas), qui retourne le nombre d’occurrences d’une valeur donnée (c’est-à-dire le nombre de fois qu’elle apparaît) dans un tableau simple.

Dans la fonction principale, ajoutez l’instruction 
printf("%d", nbOccurrences(nbHeuresParSemaine[0], 13, 4)) et observez son effet.

Notez que, de manière générale, si valeurs2d est un tableau à deux dimensions, valeurs2d[i][j] désigne une de ces cellules et valeurs2d[i] désigne un tableau qui correspond à la ligne i de valeurs2d : si on ne précise que le premier indice, on retombe sur un tableau simple.
```c
int nbOccurrences (int tab[], int taille, int valeur) {
  int nbOcc = 0;
  for (int i = 0 ; i < taille ; i++)
    if (tab[i] == valeur) nbOcc++;
  return nbOcc;
}
```
4.	Écrivez une fonction qui reçoit un horaire ainsi que le nombre de cours qu’il comporte et affiche, pour chacun de ces cours, le nombre de séances de 2h qui sont prévues. Votre fonction fera appel à nbOccurrences. 
*/

// x = semaine
#define ARRAY_SIZE_X 13
// y = cours
#define ARRAY_SIZE_Y 4

void afficheHoraire (int horaire[][ARRAY_SIZE_X], int nbCours) {
    printf("\nAffichage de l'horaire complet :\n");

    printf("          ");
    for (int iSem = 0 ; iSem < ARRAY_SIZE_X ; iSem++) {
        printf("%d %s", iSem + 1, (iSem < 9) ? " " : "");
    }
    printf("\n");

    for (int iCours = 0 ; iCours < nbCours ; iCours++) {
        printf("Cours %d :", iCours + 1);
        for (int iSem = 0 ; iSem < ARRAY_SIZE_X ; iSem++) {
            printf(" %dh", horaire[iCours][iSem]);
        }
        printf("\n");
    }
}

int nbOccurrences (int tab[], int taille, int valeur) {
    int nbOcc = 0;
    for (int i = 0 ; i < taille ; i++) {
        if (tab[i] == valeur) {
            nbOcc++;
        }
    }
    return nbOcc;
}

void afficherTotalHeuresParSemaine(int horaire[][ARRAY_SIZE_X], int nbCours) {
    printf("\nNombre total d'heures par semaine :\n");
    for (int iSemaine = 0 ; iSemaine < ARRAY_SIZE_X ; iSemaine++) {
        int totalHeures = 0;
        for (int iCours = 0 ; iCours < nbCours ; iCours++) {
            totalHeures += horaire[iCours][iSemaine];
        }
        printf("Semaine %d : %d heures\n", iSemaine + 1, totalHeures);
    }
}

void verifierHeuresCours(int horaire[][ARRAY_SIZE_X], int nbCours, int nbHeuresParCours[]) {
    printf("\nVerification des heures par cours :\n");
    for (int iCours = 0 ; iCours < nbCours ; iCours++) {
        int totalHeures = 0;
        for (int iSemaine = 0 ; iSemaine < ARRAY_SIZE_X ; iSemaine++) {
            totalHeures += horaire[iCours][iSemaine];
        }
        if (totalHeures == nbHeuresParCours[iCours]) {
            printf("Cours %d : ok\n", iCours + 1);
        } else if (totalHeures < nbHeuresParCours[iCours]) {
            printf("Cours %d : manque %d heures\n", iCours + 1, nbHeuresParCours[iCours] - totalHeures);
        } else {
            printf("Cours %d : %d heures en trop\n", iCours + 1, totalHeures - nbHeuresParCours[iCours]);
        }
    }
}

void afficherSeancesDeuxHeures(int horaire[][ARRAY_SIZE_X], int nbCours) {
    printf("\nNombre de seances de 2h par cours :\n");
    for (int iCours = 0 ; iCours < nbCours ; iCours++) {
        int nbSeances = nbOccurrences(horaire[iCours], ARRAY_SIZE_X, 2);
        printf("Cours %d : %d seance(s) de 2h\n", iCours + 1, nbSeances);
    }
}


int main(void) {
    int nbHeuresParSemaine[ARRAY_SIZE_Y][ARRAY_SIZE_X] = {
        {4, 0, 2, 2, 0, 2, 2, 0, 4, 2, 2, 0, 4},
        {0, 0, 4, 0, 4, 0, 4, 0, 4, 0, 0, 4, 0},
        {2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 2},
        {8, 2, 0, 2, 0, 2, 4, 2, 0, 4, 2, 4, 2}
    };
    int numeroCours;
    int numeroSemaine;
    int totalHeures = 0;
    int nbHeuresParCours[] = {24, 24, 20, 26};

    printf("Entrez le numero du cours  (1-4): ");
    scanf("%d", &numeroCours); // on ne vérfie pas l'entrée
    for (int iSemaine = 0 ; iSemaine < ARRAY_SIZE_X ; iSemaine++) {
        printf("Semaine %d : %d heure(s)\n", iSemaine + 1, nbHeuresParSemaine[numeroCours - 1][iSemaine]);
    }

    printf("\nEntrez le numero de la semaine (1-13): ");
    scanf("%d", &numeroSemaine); // on ne vérfie pas l'entrée
    for (int iCours = 0 ; iCours < ARRAY_SIZE_Y ; iCours++) {
        printf("Cours %d : %d heure(s)\n", iCours + 1, nbHeuresParSemaine[iCours][numeroSemaine - 1]);
    }

    printf("\nNombre total d'heures par cours :\n");
    for (int iCours = 0 ; iCours < ARRAY_SIZE_Y ; iCours++) {
        totalHeures = 0;
        for (int iSemaine = 0 ; iSemaine < ARRAY_SIZE_X ; iSemaine++) {
            totalHeures += nbHeuresParSemaine[iCours][iSemaine];
        }
        printf("Cours %d : %d heures\n", iCours + 1, totalHeures);
    }

    printf("\nOccurrences de %d dans le cours 1 : %d\n",
        nbHeuresParSemaine[0][0],
        nbOccurrences(nbHeuresParSemaine[0], ARRAY_SIZE_X, 4));

    verifierHeuresCours(nbHeuresParSemaine, ARRAY_SIZE_Y, nbHeuresParCours);
    afficherSeancesDeuxHeures(nbHeuresParSemaine, ARRAY_SIZE_Y);
    afficherTotalHeuresParSemaine(nbHeuresParSemaine, ARRAY_SIZE_Y);

    
    afficheHoraire(nbHeuresParSemaine, ARRAY_SIZE_Y);

    return EXIT_SUCCESS;
}