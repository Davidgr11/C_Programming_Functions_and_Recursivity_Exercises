//EVALUACION MULTIPLE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Constante
#define CT 7

//definici�n de la estructura, �qu� variables tiene?
struct Criterio{
    char nombre[30];
    float porcentaje;
    int calificacion;
};


//Recibe los datos, crea y llena una estructura temporal y la devuelve
struct Criterio creaCriterio(char nombre[30], float porcentaje){
    struct Criterio tmp;

    tmp.calificacion = 0;
    tmp.porcentaje = porcentaje;
    strcpy(tmp.nombre, nombre);//as� se copian las cadenas de texto

    return tmp;//devuelve la estructura que se llen�
};

//Funci�n recursiva para sumar las calificaciones
//Recibe el arreglo completo y la posici�n a revisar
float calculaTotal(struct Criterio arreglo[CT], int pos){
    float calif;
    if(pos < CT){//si es menor se repite
        calif = arreglo[pos].calificacion * arreglo[pos].porcentaje;
        return calif + calculaTotal(arreglo, pos+1);//"acumulador" de calificaciones
    }//si no, pues no y regresa 0
    return 0.0;
}

//Ordenar TODOS los criterios de menor a mayor por porcentaje
//recibe el arreglo a ordenar, como es arreglo, si se cambia en la funci�n se cambia afuera
void ordenaCriterios(struct Criterio criterios[CT]){
    int i, j;
    struct Criterio aux;//voy a mover estructuras, mi aux tambi�n debe ser estructura

    for(i=0; i<CT; i++){
        for(j=0; j<CT-1; j++){
            if(criterios[j].porcentaje > criterios[j+1].porcentaje){
                aux = criterios[j];
                criterios[j] = criterios[j+1];
                criterios[j+1] = aux;
            }
        }
    }
}

int main(){
    int i, j;
    struct Criterio criterios[3][CT];//arreglo de "conjuntos" (estructuras)
    char alumno[3][20];//nombre del alumno
    float total;//calificacion total

    //Usa la funci�n para crear cada uno de los criterios
    for(j=0; j<3; j++){
        criterios[j][0] = creaCriterio("Examen Parcial 1", 0.1);
        criterios[j][1] = creaCriterio("Examen Parcial 2", 0.15);
        criterios[j][2] = creaCriterio("Examen Parcial 3", 0.2);
        criterios[j][3] = creaCriterio("Trabajo en clase", 0.15);
        criterios[j][4] = creaCriterio("Exposicion", 0.05);
        criterios[j][5] = creaCriterio("Proyecto", 0.2);
        criterios[j][6] = creaCriterio("Practicas", 0.15);

        ordenaCriterios(criterios[j]);//env�a el arreglo desordenado, al finalizar ya est� ordenado
        /*
        for(i=0; i<CT && j == 0; i++){//recorre cada criterio e imprime el porcentaje
            printf("%s\t%.0f%%\n", criterios[0][i].nombre, criterios[0][i].porcentaje*100);
        }*/
    }

    for(i=0; i<CT; i++){//recorre cada criterio e imprime el porcentaje
        printf("%s\t%.0f%%\n", criterios[0][i].nombre, criterios[0][i].porcentaje*100);
    }

    for(j=0; j<3; j++){
        printf("Como te llamas?");
        scanf("%s", alumno[j]);

        for(i=0; i<CT; i++){//revisa cada criterio y pide la calificaci�n
            printf("Calificacion %s:", criterios[j][i].nombre);
            scanf("%d", &criterios[j][i].calificacion);
        }

        total = calculaTotal(criterios[j], 0);//calcula la suma
        printf("\n%s, tu calificacion final es: %f", alumno[j], total);
    }
    return 0;
}
