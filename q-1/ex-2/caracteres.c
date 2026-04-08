/*
Écrivez le programme qui demande et récupère un caractère. En fonction du caractère, il affiche un message. Si le caractère est une lettre (majuscule ou minuscule), un chiffre ou un symbole et sortir le message adéquat.
À l'écran doit apparaitre, si le caractère est une minuscule :

``` 
Caractère : a
C’est un caractère en minuscule !
````

Ou, dans le cas où c’est un chiffre :

``` 
Caractère : 5
C’est un chiffre !
```

Ou encore :

```
    Nombre : *
    C’est un symbole !
```
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char caractere;

    printf("Caractère : ");
    scanf(" %c", &caractere);
    
    if (caractere >= 'a' && caractere <= 'z') {
        printf("C’est un caractère en minuscule !\n");
    } else if (caractere >= 'A' && caractere <= 'Z') {
        printf("C’est un caractère en majuscule !\n");
    } else if (caractere >= '0' && caractere <= '9') {
        printf("C’est un chiffre !\n");
    } else {
        printf("C’est un symbole !\n");
    }
    return EXIT_SUCCESS;
}