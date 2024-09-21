#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeArreglo(int a[10]){
    int i;
    printf("\n");
    for(i=0; i<10; i++){
        printf("%i ", a[i]);
    }
}

void ordenaArreglo(int arreglo[10], int tam){
    int i, j, aux;
    for(i=0; i<tam-1; i++){
        for(j=i+1; j<tam; j++){
            if(arreglo[i] > arreglo[j]){
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}

int main(){
    int nums[10], i;
    srand(time(NULL));
    for(i=0; i<10; i++){
        nums[i] = rand()%10;
    }
    imprimeArreglo(nums);//imprime desordenado
    ordenaArreglo(nums, 10);//ordena
    imprimeArreglo(nums);//imprime ordenado
}
