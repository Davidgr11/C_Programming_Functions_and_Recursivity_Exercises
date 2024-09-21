#include <stdio.h>
#include <stdlib.h>
struct persona
{
    char nombre[30];
    int edad;
    char edo_civil[20];
};typedef struct persona P;

void llena (P [10],int *);
void imprime (P [10],int );
P busca_nombre (P [10],int,char[30]);

int main()
{
    P vectorP[10],personaE;
    int opc,dir=0;
    char nombreB[30];
    printf("Manejo de Estructuras \n");
    do
    {
        printf("\n 1. Llenar \n 2. Imprimir \n 3. Buscar por nombre\n 0. Salir");
        scanf("%d",&opc);
        switch(opc)
        {
            case 1: llena (vectorP,&dir);
            break;
            case 2: imprime(vectorP,dir);
            break;
            case 3:printf("\n Ingresa el nombre de persona a buscar ");
                fflush(stdin);
                gets(nombreB);
                personaE=busca_nombre(vectorP,dir,nombreB);
                printf("\n%s  %d  %s",personaE.nombre,personaE.edad,personaE.edo_civil);
                break;
            case 0:printf("\n Adios");
         }
    }while (opc!=0);
    return 0;
}

P busca_nombre(P vecP[10],int dir,char nomB[30])
{
    int i=0;
    while (i<dir && strcmp(nomB,vecP[i].nombre)!=0)
        i++;
    if (i!=dir)
        return (vecP[i]);
    else
        printf("No esta esa persona\n");
}

void llena (P vecP[10],int *dir)
{
    int i;
    while (*dir <4)
    {
        printf("\n Ingresa el nombre");
        fflush(stdin);
        gets(vecP[*dir].nombre);
        printf("\n Edad");
        scanf("%d",&vecP[*dir].edad);
        printf("\n Edo civil ");
        fflush(stdin);
        gets(vecP[*dir].edo_civil);
        *dir=*dir+1;
        //(*dir)++;
    }
        printf("\n Arreglo lleno");
}

void imprime (P vecP[10],int dir)
{
    int i;
    for (i=0;i<dir;i++)
        printf("\n %s %d %s ",vecP[i].nombre,vecP[i].edad,vecP[i].edo_civil);
}
