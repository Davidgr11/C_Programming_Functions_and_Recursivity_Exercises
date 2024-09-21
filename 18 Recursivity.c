#include<stdio.h>
#include<stdlib.h>
/*
void funcion3();
void funcion2();
void funcion1();*/
void otraFuncion(int num);

int main(){
    int num = 5;
    //funcion3();
    otraFuncion(num);
    printf("Fin%d", num);
    return 0;
}
void otraFuncion(int num){
    if(num > 0){
        otraFuncion(num-1);
    }
    printf("%d\n", num);
}/*
void funcion1(){
    int num = 1;
    printf("%d\n", num);
}

void funcion2(){
    int num = 2;
    printf("%d\n", num);
    funcion1();
}
void funcion3(){
    int num = 3;
    printf("%d\n", num);
    funcion2();
}*/
