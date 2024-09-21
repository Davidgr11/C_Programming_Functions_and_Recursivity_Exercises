#include <stdio.h>
#include <stdlib.h>
//David González Equipo 1
int main()
{
    int m1[2][2], m2[2][2], m3[2][2], r, c, a, k;

    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            printf("Dame un valor\n");
            scanf("%d", &a);
            m1[r][c]=a;
            system("cls");
        }
    }
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            printf("Dame un valor\n");
            scanf("%d", &a);
            m2[r][c]=a;
            system("cls");
        }
    }
    printf("Matriz 1\n");
     for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            printf("[%d]\t", m1[r][c]);
        }
        printf("\n");
    }
    printf("Matriz 2\n");
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            printf("[%d]\t", m2[r][c]);
        }
        printf("\n");
    }
    printf("SUMA\n");
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            m3[r][c]=m1[r][c]+m2[r][c];
            printf("[%d]\t", m3[r][c]);
        }
        printf("\n");
    }
    printf("RESTA\n");
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            m3[r][c]=m1[r][c]-m2[r][c];
            printf("[%d]\t", m3[r][c]);
        }
        printf("\n");
    }
    printf("MULTIPLICACION\n");
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            m3[r][c]=0;
            for(k=0;k<2;k++)
            {
                m3[r][c]=m3[r][c]+(m1[r][k]*m2[k][c]);
            }
            printf("[%d]\t", m3[r][c]);
        }
        printf("\n");
    }
    return 0;
}/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int a[2][2]= {{3,0} , {4,1}};
    int b[2][2] = {{1,3} , {0,2}};
    int resp[2][2] = {0};
    int x,y;
    int ren, col;

    for(y=0; y<2; y++){
        for(x=0; x<2; x++){
            printf("%d ", a[y][x]);
        }
        printf("\n");
    }
    printf("\n");
    for(y=0; y<2; y++){
        for(x=0; x<2; x++){
            printf("%d ", b[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    for(ren=0; ren<2; ren++){
        for(col=0; col<2; col++){
            resp[ren][col] = a[ren][0]*b[0][col] + a[ren][1]*b[1][col];
        }
    }

    for(ren=0; ren<2; ren++){
        for(col=0; col<2; col++){
            for(x=0; x<2; x++){
                resp[ren][col] += a[ren][x]*b[x][col];
            }
        }
    }




    for(y=0; y<2; y++){
        for(x=0; x<2; x++){
            printf("%d ", resp[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
*/
