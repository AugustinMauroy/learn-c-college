/**
 * Lisez le code suivant puis placez-le dans un programme. Modifiez-le ensuite selon les consignes données plus bas.

#define NB_REELS 100

void main(void) {
double centiemes[NB_REELS];
int i;

for(i = 0 ; i < NB_REELS ; i++){
	centiemes[i] = (double)i / 100;
}
}

1.	Déclarez un pointeur pCentieme destiné à contenir l'adresse d'un réel.

2.	Ajoutez des instructions pour
• faire pointer pCentieme vers le 3e élément du tableau et
• afficher, via printf et pCentieme, la valeur de la 3e cellule. (Vous devez voir 0.02)

3.	Ajoutez des instructions pour
• déplacer pCentieme afin de le faire pointer vers le 6e élément du tableau (via une expression arithmétique) et
• afficher le contenu de la cellule pointée. (Vous devez voir 0.05)
 
4.	Ajoutez des instructions pour
• ajouter 0.5 à la valeur pointée (celle qui se trouve dans la cellule pointée par pCentieme) et
• afficher le (nouveau) contenu de cette 6e cellule. (Vous devez voir 0.55)

5.	Déclarez un second pointeur vers un réel, pCentieme2.

6.	Si on veut faire pointer pCentieme2 vers la 56e cellule du tableau, quelles sont les instructions / groupes d’instructions qu’on peut utiliser parmi les propositions suivantes ?

pCentieme2 = centiemes;
pCentieme2 += 55;

pCentieme2 = centiemes + 55;

pCentieme2 = &centiemes[55];

Testez les 3 propositions en les ajoutant à la fin de votre code (et en affichant la valeur pointée à chaque fois) pour vérifier votre réponse.

7.	Considérez les deux instructions suivantes. Déterminez ce qu’elles font et ce qu’elles vont afficher. Ensuite, seulement, vérifiez votre réponse en les ajoutant à votre code.

printf(pCentieme == pCentieme2 ? "Vrai\n" : "Faux\n");
printf(*pCentieme == *pCentieme2 ? "Vrai\n" : "Faux\n");

8.	Finalement, faites de même avec les deux instructions suivantes. Notez aussi les formats d’affichage utilisés.

printf("%d\n", pCentieme2 - pCentieme);
printf("%lf\n", *pCentieme2 - *pCentieme);

Assurez-vous de bien comprendre la valeur qui est affichée par la première des deux instructions : en quelle « unité » cette valeur est-elle exprimée ?

 */

#include <stdio.h>
#include <stdlib.h>

#define NB_REELS 100

int main(void) {
    double centiemes[NB_REELS];
    int i;

    for(i = 0 ; i < NB_REELS ; i++){
        centiemes[i] = (double)i / 100;
    }

    double *pCentieme;

    // 2. F
    pCentieme = &centiemes[2];
    printf("3e élément: %lf\n", *pCentieme);

    // 3.
    pCentieme += 3;
    printf("6e élément: %lf\n", *pCentieme);

    // 4.
    *pCentieme += 0.5;
    printf("6e élément après ajout de 0.5: %lf\n", *pCentieme);

    // 5. 
    double *pCentieme2;

    // 6. 
    pCentieme2 = centiemes + 55;
    printf("56e élément: %lf\n", *pCentieme2);

    // 7. 
    printf(pCentieme == pCentieme2 ? "Vrai\n" : "Faux\n");
    printf(*pCentieme == *pCentieme2 ? "Vrai\n" : "Faux\n");

    // 8. 
    printf("%d\n", (int)(pCentieme2 - pCentieme));
    printf("%lf\n", *pCentieme2 - *pCentieme);

    return EXIT_SUCCESS;
}
