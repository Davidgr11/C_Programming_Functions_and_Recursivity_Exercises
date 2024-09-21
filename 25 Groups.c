#include <stdio.h>
#include <stdlib.h>

int sumar(int a[],int n);
int main()
{

    int arreglo[10];
    int total=0,respuesta;
    int tamano=10,i,posicion,subtotal;

    do
    {
    for(int i=0;i<tamano;i++)
    {
    printf("Dame un numero: ");
    scanf("%i",&arreglo[i]);
    }
    total=sumar(arreglo,tamano);


    if(total%2==0)
       {
           total=total/2;
           for(i=0;i<10;i++)
           {
         subtotal=subtotal+arreglo[i];
         if(subtotal==total)
         {
            posicion=i;
            i=10;
         }
            }
       if(posicion>0 || posicion<10)
       {
        posicion=posicion+1;

            printf("\nConjunto 1:");
            for(i=0;i<posicion;i++)
            {
             printf(" %d ",arreglo[i]);
            }
            printf("El total %d",total);
            printf("\nConjunto 2:");
            for(i=posicion;i<10;i++)
            {
             printf(" %d ",arreglo[i]);
            }
             printf("El total %d",total);
          }
          else
          {
           printf("\n2 No es posible");
          }
       }
       else
       {
         printf("\n1 No es posible");
       }

     printf("\n\n Quieres volverlo a hacer 1.Si 2.No ");
     scanf("\n%d",&respuesta);
     system("cls");
    }while(respuesta!=2);

    return 0;
}

int sumar(int a[],int n)
{
    if(n==1)
    {
        return a[0];
    }else{
        return a[n-1]+sumar(a,n-1);
    }
}

