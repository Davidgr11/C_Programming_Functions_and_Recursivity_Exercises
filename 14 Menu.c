#include <stdio.h>
#include <stdlib.h>
int sumatoria(void);
int resta(int, int*);
int multiplicacion(int, int);
void division (int*, int*);
int potencia(void);
void factorial(int*);
int potenciafactorial(int, int);
int main()
{
    printf("Menu de funciones\n");
    int op, r, a, b, aux;
    float acum;
    do{
    printf("¿Que quieres hacer?\n1)Suma n numeros\n2)Resta dos valores\n");
    printf("3)Multiplicacion sumas sucesivas\n4)Division restas sucesivas\n5)Potencia");
    printf("\n6)Factorial de un numero\n7)Potencia/factorial x^n/n!\n8)Salir\n");
    scanf("%d", &op);
    switch(op)
    {
        case 1: r=sumatoria();
                printf("EL resultado de la sumatoria es:\t%d\n", r);
                break;
        case 2: printf("Dame los valores a restar\n");
                scanf("%d %d", &a, &b);
                r=resta(a, &b);
                printf("EL resultado de la resta es:\t%d\n", r);
                break;
        case 3: printf("Dame los valores a multiplicar\n");
                scanf("%d %d", &a, &b);
                r=multiplicacion(a, b);
                printf("EL resultado de la resta es:\t%d\n", r);
                break;
        case 4: printf("Dame el dividendo y el divisor\n");
                scanf("%d %d", &a, &b);
                division(&a, &b);
                printf("EL cociente es:\t%d\nEl residuo es:\t%d\n", b, a);
                break;
        case 5: r=potencia();
                printf("EL resultado de la potencia es:\t%d\n", r);
                break;
        case 6: printf("Dame el valor de n para hacer n!\n");
                scanf("%d", &r);
                aux=r;
                factorial(&r);
                printf("EL resultado del factorial de %d es:\t%d\n", aux, r);
                break;
        case 7: printf("Dame el numero y el exponente\n");
                scanf("%d %d", &a, &b);
                r=potenciafactorial(a, b);
                factorial(&b);
                printf("El resultado de x^n/n! es:\t%d/%d\n", r, b);
                break;
        case 8: printf("Adios :)");
                break;
        default: printf("Opcion invalida\n");
    }
    }while(op!=8);
    return 0;
}
int sumatoria(void)
{
    int num, acum;
    do
    {
        printf("Dame el numero a sumar (0 para dejar de sumar)");
        scanf("%d", &num);
        acum=acum+num;
    }while(num!=0);
    return acum;
}
int resta(int x, int *y)
{
    if(x>*y)
        x=x-*y;
    else
        x=*y-x;
    return x;
}
int multiplicacion(int num1,int num2)
{
    int i, acum=0;
    for(i=0;i<num2;i++)
    {
       acum=acum+num1;
    }
    return acum;
}
void division(int *dividendo, int *divisor)
{
    int i;
    while(*dividendo>=*divisor)
    {
        *dividendo=*dividendo-*divisor;
        i++;
    }
    *divisor=i;
}
int potencia(void)
{
    int b, e, acum=1;
    printf("Dame el numero y el exponente\n");
    scanf("%d %d", &b, &e);
    while(e>0)
    {
        acum=acum*b;
        e--;
    }
    return acum;
}
void factorial(int *f)
{
    int acum=1;
    while(*f>0)
    {
        acum=acum*(*f);
        *f=*f-1;
    }
    *f=acum;
}
int potenciafactorial(int x, int y)
{
    int acum=1;
    while(y>0)
    {
        acum=acum*x;
        y--;
    }
    return acum;
}
