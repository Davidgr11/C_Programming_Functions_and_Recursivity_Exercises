#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Vania Cadena Aguilar
González Robles David Alejandro
Ángel López Vudoyra
Alethia Silvana Morán Franco
*/
struct Producto{
  int costo;
  int precio;
  int cantidad;
  char nombre[15];
};
struct Tienda{
  char nombre[30];
  struct Producto productos[5];
};
int main() {
  int i,band=1,op,op2,ganancias=0,j,acum=5;
  struct Tienda principal;
  strcpy(principal.productos[0].nombre,"Cuadernos");
   principal.productos[0].costo=30;
   principal.productos[0].precio=50;
   principal.productos[0].cantidad=10;
  strcpy(principal.productos[1].nombre,"Lapices");
   principal.productos[1].costo=4;
   principal.productos[1].precio=10;
   principal.productos[1].cantidad=15;
  strcpy(principal.productos[2].nombre,"Gomas");
   principal.productos[2].costo=7;
   principal.productos[2].precio=13;
   principal.productos[2].cantidad=12;
  strcpy(principal.productos[3].nombre,"Plumas");
   principal.productos[3].costo=3;
   principal.productos[3].precio=7;
   principal.productos[3].cantidad=20;
  strcpy(principal.productos[4].nombre,"Reglas");
   principal.productos[4].costo=7;
   principal.productos[4].precio=15;
   principal.productos[4].cantidad=16;
  strcpy(principal.nombre,"Papeleria Chonita");
  printf("¡Bienvenido a la %s!\n\n",principal.nombre);
  while(band==1 && acum!=0)
  {
    printf("¿Desea registrar una venta? 1)si otro)No");
    scanf("%d", &band);
    if(band==1)
    {
      printf("Inventario\n");

      for(i=0;i<5;i++)
      {
      printf("Cant: %d %s Precio:$%d, Costo: $%d\n",principal.productos[i].cantidad, principal.productos[i].nombre, principal.productos[i].precio, principal.productos[i].costo);
      }
       printf("¿Qué producto vendiste? \n 1)Cuaderno, 2)Lapices, 3)Gomas, 4)Plumas, 5)Reglas\n");
       scanf("%d", &op);
       op=op-1;
       printf("¿Cuántas unidades?\n");
       scanf("%d", &op2);
       principal.productos[op].cantidad=principal.productos[op].cantidad-op2;
       ganancias=ganancias+(op2*principal.productos[op].precio)-(principal.productos[op].costo*op2);
       printf("El precio de las unidades vendidas menos el costo de las mismas te da una utilidad de\n%d\n", ganancias);
       acum=5;
       for(j=0;j<5;j++)
       {
         if(principal.productos[j].cantidad==0)
         {
           acum--;
           printf("El producto %s ya no tiene disponibilidad\n",principal.productos[j].nombre);
         }
       }
    }
  }
  printf("El total de ganacias (utilidad) es:\t$%d", ganancias);
  return 0;
}
/*
Tienda
Una tienda vende 5 productos diferentes. Cada producto tiene un costo de
adquisición, un precio de venta (mayor al costo) y una cantidad. Escribe un programa que permita a la tienda administrar su inventario y
contabilizar sus ganancias, para ello el programa debe:
 Registrar las ventas de productos.
 Consultar el total de ganancias generadas.
Los datos de los productos deben estar cargados inicialmente desde el
código. Si no hay existencia de un producto, no se puede vender. Si no quedan productos en existencia, se debe mostrar un aviso y
terminar el programa. Utiliza estructuras para realizar
*/
