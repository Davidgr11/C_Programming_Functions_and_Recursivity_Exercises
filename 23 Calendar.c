#include <stdio.h>
#include <stdlib.h>

int zeller(int mes);
int calculardia(int mes);
void calendario(int mes);
int dia,i,j,cale;
int main()
{
    int mes,i;
    char d[7]={'D','L','M','M','J','V','S'};
    printf("Meses del 2021\n");
    printf("Dime el mes que quieres ver (1 a 12): \n");
    scanf("%d",&mes);

    for(i=0;i<7;i++)
    {
        printf(" %3c ",d[i]);
    }
    printf("\n");
 calendario(mes);
return 0;
}
void calendario(int mes)
{
int dia=1,i,j,cale[7][7],h=0;
int diasmes=calculardia(mes);
int z=zeller(mes);
for(i=0;i<z;i++)
{
    printf("   . ");
}
   for(i=0;i<6;i++)
   {
    for(j=z;j<7;j++)
     {
        if(dia<=diasmes)
        {
        cale[i][j]=dia;
        printf(" %3d ",cale[i][j]);
        dia++;
        z++;
        }
        z=0;
     }
     printf("\n");
   }
}
int calculardia(int mes)
{
    if(mes==1 ||mes==3 ||mes==5 ||mes==6 ||mes==8 ||mes==10 ||mes==12)
    {
        return 31;
    }
    else
    {
        if(mes==2)
        {
            return 28;
        }
        else
        {
            return 30;
        }
    }
}
int zeller(int mes)
{
    int a=(14-mes)/12;
    int b=2021-a;
    int m=mes+12*a-2;
    int dia=1,d;
    d=(dia+b+b/4-b/100+b/400+(31*m)/12)%7;
    return d;
}


