/*
```c
prixTotal = nbRepas * prixRepas;
if (nbRepas > 10)
	printf("Reduction pour plus de 10 repas");
	prixTotal = prixTotal * 0.9;
printf("A payer : %.2f euros", prixTotal);
```
Assurez-vous d’avoir compris la notion de bloc d’instructions. Sans exécuter ce bout de code, pensez-vous que la réduction est appliquée à bon escient ? Pourquoi ?

Si vous n’arrivez pas à trouver l’erreur, écrivez le tout dans nouveau fichier source reductionRepas.c :
•	Ajoutez-y les instructions nécessaires à son exécution ainsi que celles permettant de demander à l’utilisateur le nombre de repas et le prix d’un repas, et de les récupérer dans les variables adéquates.
•	Exécutez le programme en soumettant un nombre de repas supérieur à 10. Le montant final devrait être correct. 
•	Essayez maintenant avec un nombre de repas inférieur ou égal à 10. Que constatez-vous ?
•	Mettez-vous à la place du restaurateur et imaginez sa réaction… 
•	Il y a deux caractères à ajouter, lesquels ? Corrigez le programme afin qu’il fasse ce qu’il est supposé réaliser.
*/
#include <stdio.h>  
#include <stdlib.h>

int main(void) {
    int nbRepas;
    float prixRepas;
    float prixTotal;

    // Demander le nombre de repas
    printf("Entrez le nombre de repas : ");
    scanf("%d", &nbRepas);

    // Demander le prix d'un repas
    printf("Entrez le prix d'un repas : ");
    scanf("%f", &prixRepas);

    // Calculer le prix total
    prixTotal = nbRepas * prixRepas;

    // Appliquer la réduction si applicable
    if (nbRepas > 10) {
        printf("Reduction pour plus de 10 repas\n");
        prixTotal = prixTotal * 0.9;
    }

    // Afficher le montant à payer
    printf("A payer : %.2f euros\n", prixTotal);

    return EXIT_SUCCESS;
}