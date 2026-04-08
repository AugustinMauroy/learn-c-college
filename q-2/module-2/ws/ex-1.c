#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAPS_NAME_SIZE 100
#define MAPS_NUMBER_OF_KEYWORDS 3
#define MAPS_KEYWORDS_SIZE 25

typedef struct {
    char name[MAPS_NAME_SIZE]; // \0 included
    int height;
    int width;
    bool official;
    char keywords[MAPS_NUMBER_OF_KEYWORDS][MAPS_KEYWORDS_SIZE]; // \0 included
} Maps;

typedef struct {
    int heightMin;
    int heightMax;
    int widthMin;
    int widthMax;
} CritereRecherche;

int getMapSize(Maps map) {
    return map.height * map.width;
}

Maps GetMapWithLargestSize(Maps maps[], int numberOfMaps) {
    Maps largestMap = maps[0];
    int largestSize = getMapSize(largestMap);

    for (int i = 1; i < numberOfMaps; i++) {
        int size = getMapSize(maps[i]);
        if (size > largestSize) {
            largestMap = maps[i];
            largestSize = size;
        }
    }

    return largestMap;
}

void displayMap(Maps maps[], int numberOfMaps) {
    for (int i = 0; i < numberOfMaps; i++) {
        Maps map = maps[i];

        int size = getMapSize(map);
        printf("%s (%d x %d, superficie %d)\n", map.name, map.height, map.width, size);
        printf("\tcarte %sofficielle", map.official ? "" : "non-");
        printf(" - Mots-clés:");
        for (int i = 0; i < MAPS_NUMBER_OF_KEYWORDS; i++) {
            printf(" %s", map.keywords[i]);
        }
        printf("\n");
    }
}

// Fonction auxiliaire pour vérifier si une carte possède un mot-clef
bool hasKeyword(Maps map, char* keyword) {
    for (int i = 0; i < MAPS_NUMBER_OF_KEYWORDS; i++) {
        if (strcmp(map.keywords[i], keyword) == 0) {
            return true;
        }
    }
    return false;
}

// Fonction qui affiche toutes les cartes avec un mot-clef donné
void displayMapsByKeyword(char* keyword, Maps maps[], int numberOfMaps) {
    int count = 0;
    
    for (int i = 0; i < numberOfMaps; i++) {
        if (hasKeyword(maps[i], keyword)) {
            printf("%s (%d x %d, superficie %d)\n", 
                   maps[i].name, maps[i].height, maps[i].width, 
                   getMapSize(maps[i]));
            count++;
        }
    }
    
    printf("Nombre de cartes avec le mot-clef '%s' : %d\n", keyword, count);
}

// Fonction auxiliaire pour vérifier si une carte respecte un critère
bool matchCritere(Maps map, CritereRecherche critere) {
    return (map.height >= critere.heightMin && 
            map.height <= critere.heightMax &&
            map.width >= critere.widthMin && 
            map.width <= critere.widthMax);
}

// Fonction qui affiche toutes les cartes respectant un critère
void displayMapsByCritere(CritereRecherche critere, Maps maps[], int numberOfMaps) {
    int count = 0;
    
    for (int i = 0; i < numberOfMaps; i++) {
        if (matchCritere(maps[i], critere)) {
            printf("%s (%d x %d, superficie %d)\n", 
                   maps[i].name, maps[i].height, maps[i].width, 
                   getMapSize(maps[i]));
            count++;
        }
    }
    
    printf("Nombre de cartes respectant le critère : %d\n", count);
}

int main(void) {
    Maps jeuDeTest[] = {
        {"Foret enchantee remplie de dangers", 20, 30, true, {"magique", "sombre", "mysterieux"}},
        {"Ruines anciennes gardees par des golems", 25, 40, false, {"ancien", "sombre", "dangereux"}},
        {"Desert brulant avec des tempetes de sable", 15, 50, true, {"aride", "dangereux", "isole"}},
        {"Cavernes glaciales hantees", 18, 20, false, {"froid", "hante", "sombre"}},
        {"Chateau abandonne", 30, 30, true, {"ancien", "sombre", "dangereux"}},
        {"Plaines ouvertes avec tribus nomades", 40, 20, false, {"vaste", "ensoleille", "isole"}},
        {"Marecages brumeux", 12, 18, true, {"humide", "dangereux", "sombre"}},
        {"Montagnes escarpees", 20, 25, false, {"rocheux", "froid", "isole"}},
        {"Ville en ruines infestee de zombies", 25, 25, true, {"ruines", "dangereux", "horreur"}},
        {"Forteresse en feu", 15, 30, true, {"enflammee", "chaotique", "dangereux"}},
        {"Jungle luxuriante", 20, 20, false, {"tropicale", "dense", "sauvage"}},
        {"Camp militaire abandonne", 10, 15, true, {"ruines", "dangereux", "isole"}},
        {"Ile volcanique", 15, 15, true, {"volcan", "dangereux", "isole"}},
        {"Sous-sol labyrinthique", 20, 40, false, {"sombre", "complexe", "dangereux"}},
        {"Cimetiere hante", 30, 20, true, {"sombre", "hante", "dangereux"}},
        {"Temple oublie", 18, 22, false, {"ancien", "mysterieux", "reclus"}},
        {"Lac gele", 25, 25, true, {"glace", "tranquille", "isole"}},
        {"Plateau desertique", 30, 15, false, {"aride", "vaste", "isole"}},
        {"Mine abandonnee", 20, 20, true, {"souterrain", "dangereux", "ruines"}},
        {"Village enneige", 15, 25, false, {"froid", "isole", "charmant"}},
        {"Fleuve perilleux", 12, 18, true, {"rapide", "dangereux", "aquatique"}},
        {"Tour mysterieuse", 10, 10, false, {"sombre", "enigmatique", "dangereux"}},
        {"Prison souterraine", 18, 22, true, {"sombre", "oppressant", "securise"}},
        {"Cite volante", 35, 35, true, {"aerienne", "magique", "dangereux"}},
        {"Campement de bandits", 15, 20, false, {"dangereux", "hostile", "cache"}},
        {"Canyon profond", 25, 15, false, {"rocheux", "dangereux", "etroit"}},
        {"Temple sous-marin", 20, 25, true, {"aquatique", "mystique", "ancien"}},
        {"Falaise venteuse", 15, 30, false, {"isole", "dangereux", "vent"}},
        {"Plaine de bataille abandonnee", 30, 30, false, {"vaste", "dangereux", "sanglante"}},
        {"Jardin eternel", 12, 12, true, {"feerique", "floral", "enchante"}}
    };

    int nombreCartes = sizeof(jeuDeTest) / sizeof(jeuDeTest[0]);

    // Test 2: Vérifier la fonction GetMapWithLargestSize avec un trio
    printf("=== Test 2: Carte avec la plus grande superficie (3 premières cartes) ===\n");
    Maps largestInTrio = GetMapWithLargestSize(jeuDeTest, 3);
    printf("Résultat: %s (superficie: %d)\n\n", largestInTrio.name, getMapSize(largestInTrio));

    // Test 5a: Plus grande carte du jeu complet
    printf("=== Test 5a: Carte avec la plus grande superficie (toutes les cartes) ===\n");
    Maps largestMap = GetMapWithLargestSize(jeuDeTest, nombreCartes);
    printf("Résultat: %s (superficie: %d)\n\n", largestMap.name, getMapSize(largestMap));

    // Test 5b: Cartes avec le mot-clef "isole"
    printf("=== Test 5b: Cartes avec le mot-clef 'isole' ===\n");
    displayMapsByKeyword("isole", jeuDeTest, nombreCartes);
    printf("\n");

    // Test 5c: Cartes avec le mot-clef "dangereux"
    printf("=== Test 5c: Cartes avec le mot-clef 'dangereux' ===\n");
    displayMapsByKeyword("dangereux", jeuDeTest, nombreCartes);
    printf("\n");

    // Test 5d: Cartes avec hauteur entre 15 et 20, largeur entre 20 et 30
    printf("=== Test 5d: Cartes avec hauteur [15-20] et largeur [20-30] ===\n");
    CritereRecherche critere = {15, 20, 20, 30};
    displayMapsByCritere(critere, jeuDeTest, nombreCartes);

    return EXIT_SUCCESS;
}
