#include<stdio.h>
#include<stdlib.h>
#include<time.h>


float promedio(int parciales[3]){
    int i;
    int suma=0;
    for(i=0; i<3; i++){
        suma = suma+parciales[i];
    }
    return suma/3.0;
}

float masAlto(float arreglo[5]){
    //5 promedios de alumnos
    float max = 0;
    int i;
    for(i=0; i<5; i++){
        if(arreglo[i] > max ){
            max = arreglo[i];
        }
    }
    return max;
}
int main(){
    int calif[4][5][3];
    //srand(time(NULL));

    int g, a, p;
    int opc;
    int grupo;

    for(g=0; g<4; g++){
        for(a=0; a<5; a++){
            for(p=0; p<3; p++){
                //rand%(final - inicial +1) + inicial
                calif[g][a][p] = rand()%(10-5+1)+5;
            }
        }
    }

    do{
        printf("\nQue quieres hacer?\n");
        printf("1. Ver calificaciones\n");
        printf("2. Mejores alumnos\n");
        printf("3. Salir\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:

                printf("Que grupo quieres?\n");
                scanf("%d", &grupo);
                printf("\nGrupo %d\n", grupo);

                for(a=0; a<5; a++){
                    printf("alumno %d:", a);
                    for(p=0; p<3; p++){
                        printf("%d ", calif[grupo][a][p]);
                    }
                    printf("promedio: %.2f", promedio(calif[grupo][a]));
                    printf("\n");
                }
                /*
                alumno 0: 5 7 6 [6]
                alumno 1: 9 8 9
                alumno 2: 5 8 5*/

            break;
            case 2:
                //Grupo 0
                //promedio mas alto: 9

                //Grupo 1
                //promedio mas alto: 8.7

            break;
        }
    }while(opc < 3);
}
