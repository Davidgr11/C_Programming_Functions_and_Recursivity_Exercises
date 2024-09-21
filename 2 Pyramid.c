#include <stdio.h>
#include <stdlib.h>

int main()
{
    int renglones, espacios, i, ractual=1, j;
    do
    {
        printf("¿Cuantos renglones quieres?\n");
        scanf("%d", &renglones);
        if(renglones>9 || renglones<=0)
        {
            printf("Error, no es válido");
        }
    }while(renglones>9 || renglones <=0);
    j=8;
    while(ractual<=renglones)
    {
        for(i=0;i<j;i++)
        {
            printf(" ");
        }
        for(i=0;i<ractual;i++)
        {
            printf("%d ", ractual);
        }
        printf("\n");
        ractual++;
        j--;
    }
    return 0;
}
