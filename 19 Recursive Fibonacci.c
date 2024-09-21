#include <stdio.h>
#include <stdlib.h>
//David Gonzalez

int fibonacci(int);
int main()
{
    int num, i;
    printf("¿Cuantos elementos quieres de la serie\n");
    scanf("%d", &num);
    while(num<0)
    {
        printf("Número invalido\nDame otro\n");
        scanf("%d", &num);
    }
    for(i=0;i<num;i++)
    {
        printf("%d\t", fibonacci(i));
    }
}
int fibonacci(int n)
{
    if (n==0 || n==1){
        return n;
    }
    else{
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}
