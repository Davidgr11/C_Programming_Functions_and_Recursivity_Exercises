#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//David González
int main()
{
    char nombre[10][20], aux[20];
    int i, n, j;
    printf("¿Cuantos nombres quieres 1-10?\n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("¿Como te llamas?\n");
        fflush(stdin);
        gets(nombre[i]);

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(strcmp(nombre[j], nombre[j+1])>0)
            {
                strcpy(aux, nombre[j]);
                strcpy(nombre[j], nombre[j+1]);
                strcpy(nombre[j+1], aux);
            }
        }
    }
    printf("\nLos nombres en orden alfabetico son:\n");
    for(i=0;i<=n;i++)
    {
        printf("%s\n", nombre[i]);
    }
    return 0;
}
