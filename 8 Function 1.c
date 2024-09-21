#include <stdio.h>
#include <stdlib.h>

void func2(int, int*);
int main()
{
    int a, b;
    printf("Dame dos valores\n");
    scanf("%d %d", &a, &b);
    func2(b, &a);
    printf("El resultado es %d", a);
}
void func2(int y, int*x)
{
    *x=*x+y;
}
