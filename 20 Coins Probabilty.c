#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int probabilidad();

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

    for(i=0; i<20; i++){
        tipo_moneda = probabilidad();
        cont[tipo_moneda]++;
        printf("$%d ", monedas[tipo_moneda]);
    }

    printf("\n");
    for(i=0; i<3; i++){
        printf("%s tiene: %d total $%d\n", nombres[i] ,cont[i], cont[i]*monedas[i]);
    }
    return 0;
}
///////////////////////////////////////////
int probabilidad(){

int x, r=0, v[20], num;a


        num=rand()%100;
        if(num<60){
            return 0;
        }
        else if (num<60+30){
            return 1;
        }
        else{
            return 2;
        }
}/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


60% de que salga $1
30% de que salga $5
10% de salga $10
//rand%(final - inicial +1) + inicial  , el +1 es para incluir al l�mite superior
int generaMoneda(){
    //return rand()%3;//0 1 2
    int num = rand()%100; //0 1 2 3 4 5 || 6 7 8 || 9
    if(num < 60){
        return 0;
    }
    else if(num < 60+30){//90
        return 1;
    }else{
        return 2;
    }
}


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

    for(i=0; i<20; i++){
        tipo_moneda = generaMoneda();//regresa 0, 1 o 2
        cont[tipo_moneda]++;
        printf("$%d ", monedas[tipo_moneda]);
    }

    printf("\n");
    for(i=0; i<3; i++){
        printf("%s tiene: %d total $%d\n", nombres[i] ,cont[i], cont[i]*monedas[i]);
    }
    return 0;
}
*/
