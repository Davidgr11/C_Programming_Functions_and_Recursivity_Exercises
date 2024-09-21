#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char pax[20],paly[20],palz[20];
    printf("\n ingresa una frase ");
    fflush(stdin);
    gets(pax);
    printf("\n Ingresa segunda frase ");
    fflush(stdin);
    scanf("%s",paly);
    printf("\n%s \n %s\n",pax,paly);
    printf("La primer cadena mide %d",strlen(pax));
    if(strcmp(pax,paly)==0)
    {
        printf("\n las cadenas son iguales");
    }
    else
    {


        if (strcmp(pax,paly)>0)
        {
            printf("\n la cadena %s es mayor ",pax);
        }
        else
        {
            printf("\n la cadena %s es mayor ",paly);
        }
    }
    if (strlen(pax)>strlen(paly))
    {
        printf("\n La cadena %s es m�s larga que la cadena %s\n",pax,paly);
    }
    else
    {
         printf("\n La cadena %s es m�s larga que la cadena %s\n",paly,pax);
    }
    strupr(pax);
    printf("\n la primer cadena se modifico %s",pax);
    strcpy(palz,pax);
    printf("\n %s\t%s\t%s\n",pax,paly,palz);
    strcat(palz," ");
    strcat(palz,paly);
    printf("\n %s\t%s\t%s\n",pax,paly,palz);
    strncat(paly,pax,2);
     printf("\n %s\t%s\t%s\n",pax,paly,palz);
    return 0;
}
