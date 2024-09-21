#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//David Gonzalez y Vania Cadena
////////////////////////////
struct fracc{
    char nombre[10];
    int num[2];
};
////////////////////////////
void llena(struct fracc asigna[3]){
    printf("--------BIENVENIDO---------\n");
    printf("Dame el valor de la fraccion A en formato numerador, denominador\n");
    scanf("%d %d", &asigna[0].num[0], &asigna[0].num[1]);
    printf("Dame el valor de la fraccion B en formato numerador, denominador\n");
    scanf("%d %d", &asigna[1].num[0], &asigna[1].num[1]);
    asigna[2].num[0]=1;
    asigna[2].num[1]=1;
    strcpy(asigna[0].nombre, "Fraccion a");
    strcpy(asigna[1].nombre, "Fraccion b");
    strcpy(asigna[2].nombre, "Fraccion b");
}
////////////////////////////
void imprime(struct fracc asigna[3]){
    int i;
    for(i=0;i<3;i++){
        printf("%s: %d/%d\n", asigna[i].nombre, asigna[i].num[0], asigna[i].num[1]);
    }
}
////////////////////////////
void operaciones(struct fracc asigna[3], int op){
    int op2, i, a, band;
    switch(op)
    {
        case 1: printf("Que fraccion quieres escribir 0)A 1)B\n");
                scanf("%d", &op2);
                printf("Dame el valor de la fraccion en formato numerador/denominador\n");
                scanf("%d %d", &asigna[op2].num[0], &asigna[op2].num[1]);
                break;
        case 2: asigna[2].num[1]=(asigna[0].num[1])*(asigna[1].num[1]);
                asigna[2].num[0]=((asigna[0].num[0])*(asigna[1].num[1]))+((asigna[0].num[1])*(asigna[1].num[0]));
                break;
        case 3: asigna[2].num[1]=(asigna[0].num[1])*(asigna[1].num[1]);
                asigna[2].num[0]=((asigna[0].num[0])*(asigna[1].num[1]))-((asigna[0].num[1])*(asigna[1].num[0]));
                break;
        case 4: asigna[2].num[1]=(asigna[0].num[1])*(asigna[1].num[1]);
                asigna[2].num[0]=(asigna[0].num[0])*(asigna[1].num[0]);
                break;
        case 5: asigna[2].num[1]=(asigna[0].num[1])*(asigna[1].num[0]);
                asigna[2].num[0]=(asigna[0].num[0])*(asigna[1].num[1]);
                break;
        case 6: for(a=0;a<asigna[2].num[0];a++){
                    band=0;
                    for(i=2;i<11 && band==0;i++){
                        if(asigna[2].num[0]%i==0 && asigna[2].num[1]%i==0){
                            asigna[2].num[0]=asigna[2].num[0]/i;
                            asigna[2].num[1]=asigna[2].num[1]/i;
                            band=1;
                        }
                    }
                }
                break;
        case 7: printf("En que fraccion quieres copiar la fraccion C? 0)A 1)B\n");
                scanf("%d", &op2);
                asigna[op2].num[0]=asigna[2].num[0];
                asigna[op2].num[1]=asigna[2].num[1];
                break;
    }
}
////////////////////////////
int main()
{
    struct fracc asigna[3];
    int op=1;
    llena(asigna);
    imprime(asigna);
    while(op!=0){
        printf("\nElige que quieres hacer con las fracciones\n\t1)Escribir\n\t2)Sumar\n\t3)Restar\n\t4)Multiplicar\n\t5)Dividir\n\t6)Reducir\n\t7)Copiar\n\t0)Salir\n");
        scanf("%d", &op);
        system("cls");
        if(op!=0){
            operaciones(asigna, op);
            printf("RESULTADOS\n");
            imprime(asigna);
        }
    }
    return 0;
}

/*Escribe un programa que, utilizando una estructura, permita realizar operaciones con
fracciones. El programa debe tener 3 fracciones: A, B y C. Al iniciar el programa se debe solicitar el
valor de las fracciones A y B, posteriormente se debe poder realizar alguna de las
siguientes operaciones:
 Escribir, selecciona qué fracción se quiere escribir un valor, A o B
 Sumar, suma el valor de A + B y la respuesta se guarda en C
 Restar, resta el valor de A - B y la respuesta se guarda en C
 Multiplicar, multiplica el valor de A * B y la respuesta se guarda en C
 Dividir, divide el valor de A / B y la respuesta se guarda en C
 Reducir, simplifica el valor de la fracción C al mínimo
 Copiar, selecciona si el valor de la fracción C se copia en A o en B
Al finalizar la operación se debe imprimir el valor de las 3 fracciones. Las operaciones se
pueden hacer múltiples veces hasta que el usuario desee terminar el programa.*/
