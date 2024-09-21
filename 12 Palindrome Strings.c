/*
LEER UNA FRASE Y VALIDAR SI ES UN PALINDROMO….
RECUERDA QUE PUEDES LEER FRASES QUE TIENEN ESPACIO.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char pal[60];
    int i=0,j,band=0;
    printf("Ingresa una frase\n");
    fflush(stdin);
    gets(pal);
    j=strlen(pal)-1;
    printf("%d", j);
    while(i<j && band==0)
    {
        if(pal[i]==pal[j])
        {
            i++;
            j--;
        }
        else
        {
            if (pal[i]==' ')
            {
                i++;
            }
            else
            {
                if (isspace(pal[j])!=0)
                {
                    j--;
                }
                else
                {
                    band=1;
                }
            }
        }
    }
    if (band==1)
    {
        printf("\n La frase no es palindroma");
    }
    else
    {
        printf("\n La frase es palindroma");
    }

    return 0;
}
