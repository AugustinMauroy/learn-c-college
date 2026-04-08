/*
Chaque étudiant d’une haute école a accès à 10 logiciels différents, numérotés de 1 à 10. L’étudiant souhaitant lancer un logiciel doit simplement introduire le numéro du logiciel demandé.
Étape 1 : sans fonctions
Écrivez le programme qui permet d’obtenir, pour chaque étudiant, le numéro du logiciel demandé (-1 pour fin de saisie). Déterminez et affichez le nombre de fois que chaque logiciel a été demandé ainsi que le numéro du logiciel le plus demandé.
Faites attention à adapter votre DA au langage C, notamment pour l’initialisation du tableau !
Étape 2 : avec fonctions
 Écrivez le même programme, mais cette fois avec 
•	une fonction pour gérer les demandes des étudiants, et 
•	une autre pour déterminer le numéro du logiciel le plus demandé.
*/
#include <stdio.h>
#include <stdlib.h>

void gererDemandes(int demandes[], int taille) {
    int numero;

    printf("Entrez le numéro du logiciel demandé (1-10) ou -1 pour terminer: ");
    scanf("%d", &numero);

    while (numero != -1) {
        if (numero >= 1 && numero <= 10) {
            demandes[numero - 1]++;
        } else {
            printf("Numéro de logiciel invalide. Veuillez réessayer.\n");
        }
        printf("Entrez le numéro du logiciel demandé (1-10) ou -1 pour terminer: ");
        scanf("%d", &numero);
    }
}

int logicielPlusDemande(int demandes[], int taille) {
    int maxIndex = 0;

    for (int i = 1; i < taille; i++) {
        if (demandes[i] > demandes[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex + 1;
}

int main(void) {
    int demandes[10] = {0};

    gererDemandes(demandes, 10);

    printf("Nombre de demandes pour chaque logiciel:\n");
    for (int i = 0; i < 10; i++) {
        printf("Logiciel %d: %d demandes\n", i + 1, demandes[i]);
    }

    int plusDemande = logicielPlusDemande(demandes, 10);
    printf("Le logiciel le plus demandé est le numéro %d.\n", plusDemande);

    return EXIT_SUCCESS;
}
