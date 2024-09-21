#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;
    int op;
    printf("Dame dos lados del triángulo\n");
    scanf("%f %f", &a, &b);
    printf("1)Hipotenusa 2)Cateto\n");
    scanf("%d", &op);
    switch(op)
    {
        case 1: c=sqrt(pow(a, 2)+pow(b, 2));
                break;
        case 2: if(a>b)
                {
                    c=sqrt(pow(a, 2)-pow(b, 2));
                }
                else
                {
                    c=sqrt(pow(b, 2)-pow(a, 2));
                }
    }
    printf("El valor es\t%.2f", c);
    return 0;
}
