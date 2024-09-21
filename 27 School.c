#include<stdio.h>
#include<stdlib.h>
#include<time.h>


float promedio(int parciales[], float tam){
    int i;
    float suma=0;
    for(i=0; i<tam; i++){
        suma = suma+parciales[i];
    }
    return suma/tam;
}

//Deben ser 2 funciones porque ahora recibe float[]
float promedioFloat(float parciales[], float tam){
    int i;
    float suma=0;
    for(i=0; i<tam; i++){
        suma = suma+parciales[i];
    }
    return suma/tam;
}

float masAlto(float arreglo[], int tam){
    //5 promedios de alumnos
    //4 promedios de grupo
    float max = 0.0;
    int i;
    for(i=0; i<tam; i++){
        if(arreglo[i] > max ){
            max = arreglo[i];
        }
    }
    return max;
}
int main(void){
    int calif[4][5][3];
    float prom[5];
    float promGrupo[4];
    srand(time(NULL));

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
        printf("1. Ver calificaciones por grupo\n");
        printf("2. Mejores promedios de alumnos por grupo\n");
        printf("3. Mejor promedio de grupo de la escuela\n");
        printf("4. Promedio de los mejores de grupos\n");
        printf("0. Salir\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                printf("Que grupo quieres (0-3)?\n");
                scanf("%d", &grupo);
                printf("\nGrupo %d\n", grupo);
                for(a=0; a<5; a++){
                    printf("alumno %d:", a);
                    for(p=0; p<3; p++){
                        printf("%d ", calif[grupo][a][p]);
                    }
                    printf("promedio: %.2f", promedio(calif[grupo][a], 3));
                    printf("\n");
                }

            break;
            case 2:
                for(g=0; g<4; g++){
                    printf("Grupo %d\n", g);
                    for(a=0; a<5; a++){
                        prom[a] = promedio(calif[g][a], 3);
                    }
                    printf("El promedio mas alto es: %.2f\n", masAlto(prom, 5));
                }
            break;
            case 3:
                for(g=0; g<4; g++){
                    for(a=0; a<5; a++){
                        prom[a] = promedio(calif[g][a], 3);
                    }
                    promGrupo[g]=masAlto(prom, 5);
                }

                printf("El mejor grupo de la escuela tiene promedio de: %.2f", masAlto(promGrupo, 4));
            break;
            case 4:
                for(g=0; g<4; g++){
                    for(a=0; a<5; a++){
                        prom[a] = promedio(calif[g][a], 3);
                    }
                    promGrupo[g] = masAlto(prom, 5);
                }
                printf("El promedio de los mejores promedios es: %.2f", promedioFloat(promGrupo, 4));
            break;
        }
    }while(opc != 0);

}
