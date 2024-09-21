#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//MODIFICAMOS RENGLONES PARA VER COMO ACTUAN LAS CADENAS
void llena(char[4][10]);
void cambiarfrase(char [4][10], char [10], int);
void imprime(char [4][10]);
int main()
{
    int ren;
    char cad[4][10], nueva[10];
    llena(cad);
    printf("Dime que renglon quieres modificar\n");
    scanf("%d", &ren);
    printf("Dame la nueva palabra\n");
    fflush(stdin);
    gets(nueva);
    cambiarfrase(cad, nueva, ren);
    imprime(cad);
    return 0;
}
void llena(char cad[4][10])
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("Dame la palabra\n");
        fflush(stdin);
        gets(cad[i]);
    }
}
void cambiarfrase(char cad[4][10], char nuev[10], int r)
{
    while(r<0 || r>4)
    {
        printf("Renglon invalido\nDame otro renglon");
        scanf("%d", &r);
    }
    strcpy(cad[r], nuev);
}
void imprime(char cad[4][10])
{
    int i;
    printf("MATRIZ\n");
    for(i=0;i<4;i++)
    {
        printf("\n%s", cad[i]);
    }
}
