#include <stdio.h>
#include <stdlib.h>

int suma(int, int);
int main()
{
    int a, b, res;
    printf("Dame dos valores\n");
    scanf("%d %d", &a, &b);
    res=suma(a, b);
    printf("%d", a);
    printf("\nEl resultado es %d", res);
}

int suma(int x, int y)
{
    int z;
    x=x+5;
    z=x+y;
    return (z);
}
