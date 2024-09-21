#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, h;
    float x1, x2;
    printf("Dame los valores de la formula general A, B, C\n");
    scanf("%d %d %d", &a, &b, &c);
    if(a==0)
    {
        printf("Error de division entre cero");
    }
    h=pow(b, 2)-(4*a*c);
    if(h<0)
    {
        printf("Error de raiz imaginaria");
    }
    else
    {
         x1=(-(b)+sqrt(h))/(2*a);
         x2=(-(b)-sqrt(h))/(2*a);
         printf("Los valores que toma x son\nx=%.2f\nx=%.2f", x1, x2);
    }
    return 0;
}
