/*
À chaque type correspond une valeur maximum et une valeur minimum. Ces valeurs sont définies sous la forme de constantes symboliques situées dans des fichiers d’entête faisant partie des librairies standards.
Cherchez le nom du fichier d’entête qui contient les définitions des constantes entières.
Donnez les noms des deux constantes associées aux valeurs maximum et minimum du type int.
Au cas où vous ne sauriez pas comment chercher, voici une idée de mots à proposer au moteur de recherche de votre navigateur : « librairie standard c ».
Faites de même pour le type double. Commencez par trouver le fichier d’entête.
Ces constantes symboliques seront régulièrement utilisées pour traduire certains algorithmes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(void) {
    int minimum = INT_MIN;
    int maximum = INT_MAX;

    double minReel = DBL_MIN;
    double maxReel = DBL_MAX;

    return 0;
}