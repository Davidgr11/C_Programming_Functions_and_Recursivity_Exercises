#include <stdio.h>
#include <stdlib.h>

struct nombrec
{
    char np[20];
    char app[20];
    char apm[20];
};typedef struct nombrec N;


struct direccioc
{
    char calle[20];
    int num;
    char col[20];
};typedef struct direccioc D;

struct persona
{
    N nombre;
    int edad;
    char edo_civil[20];
    D direccion;
    N referencia;
};typedef struct persona P;

void llena (P [10],int *);
void imprime (P [10],int );
P busca_nombre (P [10],int,N);
void imprimeUna(P);

int main()
{
    P vectorP[10],personaE;
    int opc,dir=0;
    N nombreB;
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
            case 3:printf("\n Ingresa el nombre completo de persona a buscar ");
                fflush(stdin);
                gets(nombreB.np);
                fflush(stdin);
                gets(nombreB.app);
                fflush(stdin);
                gets(nombreB.apm);
                personaE=busca_nombre(vectorP,dir,nombreB);
                if (personaE.edad!=0)
                    imprimeUna(personaE);
                else
                    printf("\n No existe esa persona");
                break;
            case 0:printf("\n Adios");
         }
    }while (opc!=0);
    return 0;
}

void imprimeUna(P personaE)
{
    printf("\n\n%s %s %s %d  %s",personaE.nombre.np,personaE.nombre.app,personaE.nombre.apm,personaE.edad,personaE.edo_civil);
    printf("\n\t\t Direccion :%s %d %s",personaE.direccion.calle,personaE.direccion.num,personaE.direccion.col);
    printf("\n\t\t Referencia %s  %s  %s",personaE.referencia.np,personaE.referencia.app,personaE.referencia.apm);
}

P busca_nombre(P vecP[10],int dir,N nomB)
{
    int i=0;
    P estvacia={NULL};
    while (i<dir && (strcmp(nomB.np,vecP[i].nombre.np)!=0  || strcmp(nomB.app,vecP[i].nombre.app)!=0 ))
        i++;
    if (i!=dir)
        return (vecP[i]);
    else
        return estvacia;
}

void llena (P vecP[10],int *dir)
{
    int i;
    if (*dir <10)
    {
        printf("\n Ingresa el nombre Propio");
        fflush(stdin);
        gets(vecP[*dir].nombre.np);
        printf("\n Ingresa el Apellido Paterno");
        fflush(stdin);
        gets(vecP[*dir].nombre.app);
        printf("\n Ingresa el Apellido Materno");
        fflush(stdin);
        gets(vecP[*dir].nombre.apm);
        printf("\n Edad");
        scanf("%d",&vecP[*dir].edad);
        printf("\n Edo civil ");
        fflush(stdin);
        gets(vecP[*dir].edo_civil);
        printf("\n Ingresa tu direccion Calle");
        fflush(stdin);
        gets(vecP[*dir].direccion.calle);
        printf("\n Numero");
        scanf("%d",&vecP[*dir].direccion.num);
        printf("\n Colonia");
        fflush(stdin);
        gets(vecP[*dir].direccion.col);
        printf("\n Ingresa el nombre Propio de Referencia");
        fflush(stdin);
        gets(vecP[*dir].referencia.np);
        printf("\n Ingresa el Apellido Paterno de Referencia");
        fflush(stdin);
        gets(vecP[*dir].referencia.app);
        printf("\n Ingresa el Apellido Materno de Referencia");
        fflush(stdin);
        gets(vecP[*dir].referencia.apm);
        *dir=*dir+1;
        //(*dir)++;
    }
    else
        printf("\n Arreglo lleno");
}

void imprime (P vecP[10],int dir)
{
    int i;
    for (i=0;i<dir;i++)
    {
        printf("\n %s %s %s %d %s ",vecP[i].nombre.np,vecP[i].nombre.app,vecP[i].nombre.apm,vecP[i].edad,vecP[i].edo_civil);
        printf("\n\t\t Direccion :%s %d %s",vecP[i].direccion.calle,vecP[i].direccion.num,vecP[i].direccion.col);
        printf("\n\t\t Referencia %s %s %s",vecP[i].referencia.np,vecP[i].referencia.app,vecP[i].referencia.apm);
    }

}
//CÓDIGO CON DOS ESTRUCTURAS SECUNDARIAS.
