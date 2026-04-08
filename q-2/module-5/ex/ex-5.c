#include <stdio.h>
#include <stdlib.h>

struct ElementCode {
    char character;
    int displacement;
};
typedef struct ElementCode ElementCode;

void decodeEtAffiche(ElementCode* message, int startIndex) {
    int currentIndex = startIndex;

    while (message[currentIndex].displacement != 0) {
        printf("%c", message[currentIndex].character);
        currentIndex += message[currentIndex].displacement;
    }

    printf("%c\n", message[currentIndex].character);
}

int main(void) {
    ElementCode message[] = {
		{ 'd', 25 }, { '!', 0 }, { 'c', 27 }, { 's', 48 }, { 't', 8 }, { 'o', 10 }, { ' ', 8 }, { ' ', 23 }, { 'o', 10 }, { 'r', 46 }, { 'p', 37 }, { 'e', 12 }, { 'i', 25 }, { 'e', 43 }, { 'f', 17 }, { 'n', 51 }, { 's', 27 }, { 'n', 19 }, { 'd', 9 }, { 'r', -6 }, { 'c', -12 }, { 'a', 25 }, { 'i', 18 }, { 'c', 30 }, { 'n', 21 }, { 'e', 38 }, { 'e', 9 }, { 'e', 35 }, { 'p', 32 }, { 'i', 40 }, { 'c', 35 }, { 'a', -29 }, { ' ', -32 }, { 'L', 19 }, { 'a', -6 }, { ' ', -19 }, { 't', -4 }, { 'o', -13 }, { 'g', 32 }, { 'a', 2 }, { 't', 18 }, { 'v', 23 }, { 'l', -31 }, { 'i', 6 }, { 't', -10 }, { ',', -38 }, { 'm', 13 }, { 'r', 7 }, { 'a', -44 }, { ' ', -44 }, { 'e', -47 }, { 't', -45 }, { 'a', 16 }, { 'h', -31 }, { 'o', -16 }, { ' ', 2 }, { 'f', -14 }, { 'd', 10 }, { ' ', -19 }, { 'm', -11 }, { 'e', -51 }, { ' ', -41 }, { ' ', -61 }, { ' ', -19 }, { 'a', -47 }, { '\'', -15 }, { ' ', -47 }, { 'u', -6 }, { ' ', -58 }, { 'l', -43 }, { 'r', -49 }
    };

    decodeEtAffiche(message, 33);

    return EXIT_SUCCESS;
}
