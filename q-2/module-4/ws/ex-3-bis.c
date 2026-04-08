#include <stdio.h>
#include <stdlib.h>

void trim(char *str) {
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') i++;
    
    if (str[i] == '\n') str[i - 1] = '\0';
}

int main(void) {
    char line[200];

    FILE *recipe = fopen("cocktail.txt", "r");
    FILE *html = fopen("cocktail.html", "w");

    if (recipe == NULL) {
        printf("ENOENT\n");
        return EXIT_FAILURE;
    }

    // report it in HTML format
    // 1. write the header of the HTML file
    fprintf(html, "<!DOCTYPE html>\n");
    fprintf(html, "<html lang=\"fr\">\n");
    fprintf(html, "<head>\n");
    fprintf(html, "\t<meta charset=\"UTF-8\">\n");
    fprintf(html, "\t<title>Cocktail</title>\n");
    fprintf(html, "</head>\n");
    fprintf(html, "<body>\n");

    // 2. write title of page
    fprintf(html, "\t<h1>Cocktail de Noël</h1>\n");

    // 3. write the ingredients in an unordered list
    fprintf(html, "\t<h2>Ingrédients</h2>\n");
    fprintf(html, "\t<ul>\n");
    for (int i = 0; i < 5; i++) {
        fgets(line, 200, recipe);
        trim(line);
        fprintf(html, "\t\t<li>%s</li>\n", line);
    }
    fprintf(html, "\t</ul>\n");

    // 4. write the recipe in an ordered list
    fprintf(html, "\t<h2>Recette</h2>\n");
    fprintf(html, "\t<ol>\n");
    for (int i = 0; i < 4; i++) {
        fgets(line, 200, recipe);
        trim(line);
        fprintf(html, "\t\t<li>%s</li>\n", line);
    }
    fprintf(html, "\t</ol>\n");

    // 5. write the footer of the HTML file
    fprintf(html, "</body>\n");
    fprintf(html, "</html>\n"); 

    fclose(recipe);
    fclose(html);

    return EXIT_SUCCESS;
}
