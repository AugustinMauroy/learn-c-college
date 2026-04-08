#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fichier;
	
	fichier = fopen("ecriture.html", "w");

	fprintf(fichier, "<!DOCTYPE html>\n");
	fprintf(fichier, "<html>\n");
	fprintf(fichier, "<body>\n");
	fprintf(fichier, "<h1>Pour ecrire dans un fichier texte en C</h1>\n");
	fprintf(fichier, "<ol>\n");
	fprintf(fichier, "  <li>Ouvrir le fichier via <code>fopen</code></li>\n");
	fprintf(fichier, "  <li>Ecrire via <code>fprintf</code></li>\n");
	fprintf(fichier, "  <li>Fermer le fichier via <code>fclose</code></li>\n");
	fprintf(fichier, "</ol>\n");
	fprintf(fichier, "</body>\n");
	fprintf(fichier, "</html>");

	fclose(fichier);

    return EXIT_SUCCESS;
}
