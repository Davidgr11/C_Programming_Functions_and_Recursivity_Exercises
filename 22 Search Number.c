#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//David Gonzalez y Vania Cadena
//////////////////////
void llena(char num[50]);
void imprime(char num[50]);
void ordenar(char num[50]);
int busqueda(char num[50], int, int, int);
//////////////////////
int main()
{
    int buscar, num[50]={0};
    printf("\tDesordenado\n\n");
    llena(num);
    imprime(num);
    printf("\n\tOrdenado\n\n");
    ordenar(num);
    imprime(num);
    printf("¿Que numero quieres buscar?\n");
    scanf("%d", &buscar);
    while(buscar!=0){
    int alto=50, bajo=0, r;
    int i, j;
    r=busqueda(num, buscar, alto, bajo);
    if(r==0)
    {
        printf("\nEl numero %d si existe\n", buscar);
    }
    else
    {
        printf("\nEl numero %d no existe\n", buscar);
    }
    printf("¿Que numero quieres buscar?\n");
    scanf("%d", &buscar);}
    return 0;
}
//////////////////////
void llena(char num[50])
{
    int i, j, x, ok;
    srand(time(NULL));
    for(i=0;i<50;i++)
    {
        do
        {
        x=rand()%100+1;
        ok=1;
        for(j=0;j<50 && ok==1;j++)
        {
            if(x==num[j])
            {
                ok=0;
            }
        }
        }while(ok==0);
        num[i]=x;
    }
}
//////////////////////
void imprime (char num[50])
{
    int i;
    for(i=0;i<50;i++)
    {
        printf("%d\n", num[i]);
    }
}
////////////////////////
void ordenar(char num[50])
{
    int i, j, aux;
    for(i=0;i<50;i++)
    {
        for(j=0;j<49;j++)
        {
            if(num[j]>num[j+1])
            {
                aux=num[j];
                num[j]=num[j+1];
                num[j+1]=aux;
            }
        }
    }
}
//////////////////////////
int busqueda(char num[50], int buscar, int maxi, int mini)
{
    int medio, r;
    if(mini<=maxi)
    {
        medio=(maxi+mini)/2;
        if(buscar==num[medio])
        {
            r=0;
        }
        else
        {
            if(buscar<num[medio])
            {
                maxi=medio-1;
                r=busqueda(num, buscar, maxi, mini);
            }
            else
            {
                mini=medio+1;
                r=busqueda(num, buscar, maxi, mini);
            }
        }
    }
    return r;
}
