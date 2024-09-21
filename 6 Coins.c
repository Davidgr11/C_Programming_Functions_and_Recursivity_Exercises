#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//David González Equipo 1
int main()
{
    int x, r=0, v[10], adrian=0, beatriz=0, carlos=0;
    srand(time(NULL));
    while(r<10)
    {
        x=rand()%10+1;
        if(x==1 || x==5 || x==10)
        {
            switch(x)
            {
                case 1: adrian++;
                        break;
                case 5: beatriz++;
                        break;
                case 10: carlos++;
                        break;
            }
            v[r]=x;
            printf("%d\t", v[r]);
            r++;
        }
    }
    printf("\nAdrian: %d\t $%d\n", adrian, adrian*1);
    printf("Beatriz: %d\t $%d\n", beatriz, beatriz*5);
    printf("Carlos: %d\t $%d\n", carlos, carlos*10);
    return 0;
}
/* OTRA FORMA DE HACERLO
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int tipo_moneda;
    int cont[3]={0};
    int monedas[3] = {1,5,10};
    char nombres[3][8] = {
            {"Adrian"},
            {"Beatriz"},
            {"Carlos"}
        };
    int i;
    srand(time(NULL));

    for(i=0; i<10; i++){
        tipo_moneda = rand()%3;//0 1 2
        cont[tipo_moneda]++;
        printf("$%d ", monedas[tipo_moneda]);
    }

    printf("\n");
    for(i=0; i<3; i++){
        printf("%s tiene: %d total $%d\n", nombres[i] ,cont[i], cont[i]*monedas[i]);
    }
    return 0;
}*/
