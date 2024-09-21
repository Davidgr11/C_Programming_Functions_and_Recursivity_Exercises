#include<stdio.h>
#include<stdlib.h>

//
//8+7+6+5+4+3+2+1
//5+4+3+2+1
//3+2+1
//1
int suma(int num){
    if(num == 1){
        //ya no se repite
        return 1;//num
    }else{
        return num + suma(num-1);
//                   |<-  1  ->|
    }
}
int factorial(int num){
    if(num == 1){
        //ya no se repite
        return 1;//num
    }else{
        return num * factorial(num-1);
//                   |<-  1  ->|
    }
}


int main(){
    int num = 4;
    int total;
    total = suma(num);
    printf("Total: %d", total );
    total = factorial(num);
    printf("\nTotal: %d", total );
}
