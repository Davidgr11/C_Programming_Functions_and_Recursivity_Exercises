#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//David González Equipo 1
int main()
{
    srand(time(NULL));
    int i,V[10],aux,p=1,cont;
    char dir;
    for(i=0;i<10;i++)
    {
        V[i]=rand()%20+1;
    }
    do
    {
        cont=0;
        printf("\n");
        for(i=0;i<10;i++)
        {
            printf("[%d]",V[i]);
        }
        printf("\n\nEn que direccion?(d/i):\t");
        fflush(stdin);
        scanf("%c",&dir);
        if (dir=='i'||dir=='I'||dir=='d'||dir=='D')
        {
            printf("\nCuantas posiciones?:\t");
            scanf("%d",&p);
            while(cont<p)
            {
                if(dir=='i'||dir=='I')
                {
                    for(i=0;i<9;i++)
                    {
                        aux=V[i+1];
                        V[i+1]=V[i];
                        V[i]=aux;
                    }
                }
                else
                {
                    if (dir=='d'||dir=='D')
                    {
                        for(i=9;i>0;i--)
                        {
                            aux=V[i-1];
                            V[i-1]=V[i];
                            V[i]=aux;
                        }
                    }
                }
                cont++;
            }
        }
        else
        {
            printf("\nError de letra");
        }
    }while(p!=0);
    printf("\nFin\n");
    return 0;
}/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int arreglo[10];
    int aux, i;
    char dir;
    int cuanto, n;

    srand(time(NULL));

    for(i=0; i<10; i++){
        arreglo[i] = rand()%(20)+1;
        printf("%d ", arreglo[i]);
    }

    do{
        printf("\n");
        printf("Cuantas posiciones quieres moverlo?");
        scanf("%d", &n);
        cuanto = n;
        if(n != 0){
            printf("\n");
            fflush(stdin);//antes de char
            printf("En que direccion lo quieres mover? D o I?");
            scanf("%c", &dir);

            if(dir == 'D' || dir == 'd'){
                while(cuanto>0){
                    aux = arreglo[9];
                    //mover todas a la derecha
                    for(i=8; i>=0; i--){
                        arreglo[i+1] = arreglo[i];// 1 1 2
                    }
                    arreglo[0] = aux;
                    cuanto--;
                }

            }else if(dir == 'I' || dir == 'i'){
                while(cuanto>0){
                    aux = arreglo[0];
                    //mover todas a la derecha
                    for(i=1; i<10; i++){
                        arreglo[i-1] = arreglo[i];// 1 1 2
                    }
                    arreglo[9] = aux;
                    cuanto--;
                }
            }

            for(i=0; i<10; i++){
                printf("%d ", arreglo[i]);
            }
        }
    }while(n != 0);

    return 0;
}
*/
