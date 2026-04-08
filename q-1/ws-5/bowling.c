/*
(2)	Dans un nouveau fichier bowling.c, déclarez le tableau scores comme montré précédemment. Ne l’initialisez pas ! 
Écrivez les instructions permettant d’afficher l’indice, l’adresse (utilisez "%p" comme format d’affichage) et la valeur de chacune des cellules. 
Pensez à nouveau à utiliser la structure de contrôle adéquate afin d’éviter la répétition de code.
Compilez puis exécutez le programme.
(a)	Observez l’adresse affichée pour chacun des éléments. 
Vous remarquez qu’elles sont en effet consécutives dans la mémoire, puisque séparées de 4 bytes, taille d’un entier.
(b)	Observez la valeur affichée pour chacun des éléments. 
Vous remarquez que ces valeurs n’ont pas de sens.
Dans le programme ci-dessus, vous n’avez fait que déclarer le tableau, sans affecter de valeurs aux cellules. Les valeurs affichées sont donc le résultat de l’interprétation de ce qui se trouve actuellement en mémoire à ces adresses-là.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int scores[10];

    for (int i = 0; i < 10; i++) {
        printf("Indice: %d, Adresse: %p, Valeur: %d\n", i, (void*)&scores[i], scores[i]);
    }

    return EXIT_SUCCESS;
}
