#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x;
    char cad[20];
    printf("Dame una cadena\n");
    fflush(stdin);
    // NO PERMITE ESPACIOS scanf("%s", &cad);
    gets(cad);
    printf("\n%s\t oh si bb\n", cad);
    puts(cad);
    x=strlen(cad);
    printf("La longitud de la cadena es %d", x);
    //printf("El ultimo caracter es %c",);
    return 0;
}
