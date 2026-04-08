#include <stdio.h>

void main(void) {
	int âgeActuel;
	printf("Entrez votre âge : ");
	scanf("%d", &âgeActuel);
	printf("Dans un an, vous aurez %d ans !\n", âgeActuel + 1);
	printf("Dans deux ans, vous aurez %d ans !\n", âgeActuel + 2);
}
