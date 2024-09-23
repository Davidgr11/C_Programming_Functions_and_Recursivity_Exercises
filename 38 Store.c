/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//David
struct Categoria
{
    char cat;
    char tipo;
    int fecha;
    int expiracion;
    int mes;
    int ao;
    int pasillo;
    char pasle;
};

struct Producto
{
    char nombre[20];
    int precio;
    struct Categoria categoria;
};


struct Producto agregar(struct Producto producto[],int total,int cont[5])
{
    struct Producto tmp;
    int band=0,band2=0,band3=0;
    printf("\nDame nombre del producto:\t");
    scanf("%s",tmp.nombre);
    printf("\nDame el precio del producto\t");
    scanf("%d",&tmp.precio);
    do
    {
    printf("\nDame la categoria del producto");
    printf("\nCategorias: \n-'M' para carne \n-'P' para frutas y verduras \n-'D' para lacteos \n-'C' para productos enlatados \n-'N' para objetos o cosas que no sean comida");
    printf("\nOpcion:\t");
    fflush(stdin);
    scanf("%c",&tmp.categoria.cat);
    tmp.categoria.cat=toupper(tmp.categoria.cat);
    if(tmp.categoria.cat!='M' && tmp.categoria.cat!='P' && tmp.categoria.cat!='D' && tmp.categoria.cat!='C'&& tmp.categoria.cat!='N')
    {
        printf("\nCategoria incorrecta");
        band=0;
    }
    else
    {
        band=1;
    }
    }while(band==0);

    switch(tmp.categoria.cat)
    {
        case 'M':
            cont[0]++;
            do
            {
            printf("\nQue tipo de carne es?");
            printf("\nTipos: \n-'R' para carne roja \n-'P' para carne de puerco \n-'F' para pescado");
            printf("\nOpcion:\t");
            fflush(stdin);
            scanf("%c",&tmp.categoria.tipo);
            tmp.categoria.tipo=toupper(tmp.categoria.tipo);
            if(tmp.categoria.tipo!='R' && tmp.categoria.tipo!='P' && tmp.categoria.tipo!='F')
            {
                printf("\nCategoria de carne incorrecta");
                band2=0;
            }
            else
            {
                band2=1;
            }
            }while(band2==0);
            printf("\nIngresa la fecha en formato ddmmaa:\t");
            scanf("%d",&tmp.categoria.fecha);
            printf("\nIngresa la fecha  de vencimiento en formato ddmmaa:\t");
            scanf("%d",&tmp.categoria.expiracion);
        break;

        case 'P':
            cont[1]++;
            do
            {
            printf("\nQue es?");
            printf("\nTipos: \n-'V' para verduras \n-'F' para frutas");
            printf("\nOpcion:\t");
            fflush(stdin);
            scanf("%c",&tmp.categoria.tipo);
            tmp.categoria.tipo=toupper(tmp.categoria.tipo);
            if(tmp.categoria.tipo!='V' && tmp.categoria.tipo!='F' && tmp.categoria.tipo!='F')
            {
                printf("\nCategoria incorrecta");
                band2=0;
            }
            else
            {
                band2=1;
            }
            }while(band2==0);
            printf("\nIngresa la fecha en la que se recibio el producto en formato ddmmaa:\t");
            scanf("%d",&tmp.categoria.fecha);

        break;

        case 'D':
            cont[2]++;
            printf("\nIngresa la fecha  de vencimiento en formato ddmmaa:\t");
            scanf("%d",&tmp.categoria.expiracion);

        break;
        case 'C':
            cont[3]++;
            printf("\nIngresa el mes de vencimiento en formato mm:\t");
            scanf("%d",&tmp.categoria.mes);
            printf("\nIngresa el año de vencimiento en formato aaaa:\t");
            scanf("%d",&tmp.categoria.ao);
            printf("\nIngresa el numero de pasillo:\t");
            scanf("%d",&tmp.categoria.pasillo);
            do
            {
            printf("\nEn que lado?");
            printf("\n-'A' o 'B'");
            printf("\nOpcion:\t");
            fflush(stdin);
            scanf("%c",&tmp.categoria.pasle);
            tmp.categoria.pasle=toupper(tmp.categoria.pasle);
            if(tmp.categoria.pasle!='A' && tmp.categoria.pasle!='B')
            {
                printf("\nLado incorrecta");
                band2=0;
            }
            else
            {
                band2=1;
            }
            }while(band2==0);

        break;
        case 'N':
            cont[4]++;
            do
            {
            printf("\nQue categoria es?:");
            printf("\n-'C'para producto de limpieza \n-'F' para farmacia \n-'O'para otro");
            printf("\nOpcion:\t");
            fflush(stdin);
            scanf("%c",&tmp.categoria.tipo);
            tmp.categoria.tipo=toupper(tmp.categoria.tipo);
            if(tmp.categoria.tipo!='c' && tmp.categoria.tipo!='F'&& tmp.categoria.tipo!='O')
            {
                printf("\nLado no existe");
                band2=0;
            }
            else
            {
                band2=1;
            }
            }while(band2==0);
            printf("\nIngresa el numero de pasillo:\t");
            scanf("%d",&tmp.categoria.pasillo);
            do
            {
            printf("\nEn que lado?");
            printf("\n-'A' o 'B'");
            printf("\nOpcion:\t");
            fflush(stdin);
            scanf("%c",&tmp.categoria.pasle);
            tmp.categoria.pasle=toupper(tmp.categoria.pasle);
            if(tmp.categoria.pasle!='A' && tmp.categoria.pasle!='B')
            {
                printf("\nLado  no existe");
                band3=0;
            }
            else
            {
                band3=1;
            }
            }while(band3==0);
        break;
        default:printf("\nOpcion invalida");
    }
    return tmp;

}


int main()
{
    struct Producto producto[50];
    int cont[5];
    int opcion,band=0,total=0,band2=0,i=0;
    cont[0]=0;
    cont[1]=0;
    cont[2]=0;
    cont[3]=0;
    cont[4]=0;

    printf("Tienda\n");
    do
    {
    printf("\nIngresa la opcion deseada \n-1.Ingresar producto \n-2.Ver productos \n-3.Salir \nOpcion:\t");
    scanf("%d",&opcion);
        switch(opcion)
    {
        case 1:
            printf("\nIngresar producto");
             if(total<50)
             {
               producto[total]=agregar(producto,total,cont);
               total++;
               printf("\nEl producto se guardo correctamente");
             }
            if(total>=50)
             {
                 printf("\nYa no puedes ingresar mas productos");
             }

        band=0;
        break;

        case 2:
            do
        {
        printf("\nQue categoria deseas imprimir \n-1.Carnes \n-2.Frutas y verduras \n-3.Lacteos \n-4.Productos enlatados \n-5.Otros \n-6.Salir \nOpcion:\t");
        scanf("%d",&opcion);
            switch(opcion)
                {
                case 1:
                    printf("\nCARNE");
                    printf("\nHay %d productos de esta categoria\n",cont[0]);
                    if(cont[0]!=0)
                    {
                           for(i=0;i<total;i++)
                        {
                            if(producto[i].categoria.cat=='M')
                            {
                                printf("\n-%s \nTipo de carne %c \nPrecio: $%d \nFecha de empaque: %d \nFecha de vencimiento: %d",producto[i].nombre,producto[i].categoria.cat,producto[i].precio,producto[i].categoria.fecha,producto[i].categoria.expiracion);
                            }
                        }

                    }

                band2=0;
                break;

                case 2:
                    printf("\nVERDURAS Y FRUTAS");
                    printf("\nHay %d productos de esta categoria\n",cont[1]);
                    if(cont[1]!=0)
                    {
                           for(i=0;i<total;i++)
                        {
                            if(producto[i].categoria.cat=='P')
                            {
                                printf("\n-%s \nCategoria: %c Precio: $%d \nRecibido en la fecha: %d",producto[i].nombre,producto[i].categoria.tipo,producto[i].precio,producto[i].categoria.fecha);
                            }
                        }

                    }

                band2=0;
                break;

                case 3:
                    printf("\nLACTEOS");
                    printf("\nHay %d productos de esta categoria\n",cont[2]);
                      if(cont[2]!=0)
                    {
                           for(i=0;i<total;i++)
                        {
                            if(producto[i].categoria.cat=='D')
                            {
                                printf("\n-%s \nPrecio: $%d \nVence el dia %d",producto[i].nombre,producto[i].precio,producto[i].categoria.fecha);
                            }
                        }

                    }


                band2=0;
                break;
                case 4:
                    printf("\nPRODUCTOS ENLATADOS");
                    printf("\nHay %d productos de esta categoria\n",cont[3]);
                         if(cont[3]!=0)
                    {
                           for(i=0;i<total;i++)
                        {
                            if(producto[i].categoria.cat=='C')
                            {
                                printf("\n-%s \nPrecio: $%d \nVence el mes %d y a%co %d Pasillo: %d %c",producto[i].nombre,producto[i].precio,producto[i].categoria.mes,164,producto[i].categoria.ao,producto[i].categoria.pasillo,producto[i].categoria.pasle);
                            }
                        }

                    }

                band2=0;
                break;
                case 5:
                    printf("\nOTROS");
                    printf("\nHay %d productos de esta categoria\n",cont[4]);
                         if(cont[4]!=0)
                    {
                           for(i=0;i<total;i++)
                        {
                            if(producto[i].categoria.cat=='N')
                            {
                                printf("\n-%s  \nCategoria: %c Precio: $%d \nPasillo: %d %c",producto[i].nombre,producto[i].categoria.tipo,producto[i].precio,producto[i].categoria.pasillo,producto[i].categoria.pasle);
                            }
                        }

                    }


                band2=0;
                break;

                case 6:
                    band2=1;
                    break;
                default:printf("\nOpcion invalida");
                }
                }while (band2==0);


        band=0;
        break;

        case 3:
            band=1;
            break;
        default:printf("\nOpcion invalida");
    }
    }
    while (band==0);
    if (band==1)
    {
        printf("\nFin de programa");
    }
    return 0;
}
*/
#include <stdio.h>
#include <ctype.h>
typedef struct{
  char nombre[20];
  int precio;
  int caducidad[2];
  int empaquetado[2];
  char pasillo[4];
  char clasificacion;
  int conttipoprod;
  }Tienda;
void acomodador(Tienda productos[50][5],int producto,int cont){
  fflush(stdin);
  printf("Dame el nombre del producto: ");
  scanf("%s",productos[cont][producto-1].nombre);
  printf("Dame el precio en centavos: ");
  scanf("%d",&productos[cont][producto-1].precio);
  switch(producto){
    case 1:
    do{
    fflush(stdin);
    printf("Que tipo de carne es? R=Res, A=Aves, P=Pescado: ");
    scanf(" %c",&productos[cont][producto-1].clasificacion);
    productos[cont][producto-1].clasificacion=toupper(productos[cont][producto-1].clasificacion);
    }while(productos[cont][producto-1].clasificacion!='R' && productos[cont][producto-1].clasificacion!='A' && productos[cont][producto-1].clasificacion!='P');
    printf("Cual es el mes de empaquetado?: ");
    scanf("%d",&productos[cont][producto-1].empaquetado[0]);
    printf("Cual es el annio de empaquetado?: ");
    scanf("%d",&productos[cont][producto-1].empaquetado[1]);
    printf("Cual es el mes de caducidad?: ");
    scanf("%d",&productos[cont][producto-1].caducidad[0]);
    printf("Cual es el annio de caducidad?: ");
    scanf("%d",&productos[cont][producto-1].caducidad[1]);
    productos[0][producto-1].conttipoprod+=1;
    break;
    case 2:
    do{
      fflush(stdin);
      printf("Que es? F=Fruta V=Verdura: ");
      scanf(" %c",&productos[cont][producto-1].clasificacion);
      productos[cont][producto-1].clasificacion=toupper(productos[cont][producto-1].clasificacion);
    }while(productos[cont][producto-1].clasificacion!='V' && productos[cont][producto-1].clasificacion!='F');
    printf("En que mes se recibio el producto?: ");
    scanf("%d",&productos[cont][producto-1].empaquetado[0]);
    printf("En que annio fue recibido el producto?: ");
    scanf("%d",&productos[cont][producto-1].empaquetado[1]);
    productos[0][producto-1].conttipoprod+=1;
    break;
    case 3:
    printf("En que mes caduca el producto?: ");
    scanf("%d",&productos[cont][producto-1].caducidad[0]);
    printf("En que annio caduca el producto?: ");
    scanf("%d",&productos[cont][producto-1].caducidad[2]);
    productos[0][producto-1].conttipoprod+=1;
    break;
    case 4:
    printf("En que mes caduca el producto?: ");
    scanf("%d",&productos[cont][producto-1].caducidad[0]);
    printf("En que annio caduca el producto?: ");
    scanf("%d",&productos[cont][producto-1].caducidad[1]);
    printf("En que pasillo y lado del mismo se encuentra? (Ej. 12A o 12B): ");
    scanf("%s",productos[cont][producto-1].pasillo);
    productos[0][producto-1].conttipoprod+=1;
    break;
    case 5:
    do{
    fflush(stdin);
    printf("Como se puede clasificar? L=Limpieza F=Farmacia O=Otro: ");
    scanf(" %c",&productos[cont][producto-1].clasificacion);
    productos[cont][producto-1].clasificacion=toupper(productos[cont][producto-1].clasificacion);
    }while(productos[cont][producto-1].clasificacion!='L' && productos[cont][producto-1].clasificacion!='F' && productos[cont][producto-1].clasificacion!='O');
    printf("En que pasillo y lado del mismo se encuentra? (Ej. 12A o 12B): ");
    scanf("%s",productos[cont][producto-1].pasillo);
    productos[0][producto-1].conttipoprod+=1;
    break;
  }
}

int llamador(Tienda productos[50][5],int producto,int cont){
  acomodador(productos,producto,cont);
    printf("Producto guardado con exito!!\n\n");
    return cont+1;
}
void impresorbasico(Tienda productos[50][5],int j,int k){
  printf("%s %dc ",productos[j][k].nombre,productos[j][k].precio);
}
int main(){
    Tienda productos[50][5];
    int producto,j=0,k=0,cont0=0,cont1=0,cont2=0,cont3=0,cont4=0;
    for(j=0;j<50;j++)for(k=0;k<5;k++)
    productos[j][k].conttipoprod=0;
    do{
  printf("Bienvenido al clasificador\n\n");
  printf("\n1.Guardar carnes\n2.Guardar frutas y/o verduras\n3.Guardar lacteos\n4.Guardar enlatados\n5.Guardar otros\n6.Ver productos\n7.salir\n\n");
  printf("Que opcion desea?: ");
  scanf("%d",&producto);
  switch(producto){
    case 1:
    cont0=llamador(productos,producto,cont0);
    break;
    case 2:
    cont1=llamador(productos,producto,cont1);
    break;
    case 3:
    cont2=llamador(productos,producto,cont2);
    break;
    case 4:
    cont3=llamador(productos,producto,cont3);
    break;
    case 5:
    cont4=llamador(productos,producto,cont4);
    break;
    case 6:
    if(productos[0][0].conttipoprod>0){printf("Carnes\n\n");
    for(j=0;j<cont0;j++){
      impresorbasico(productos,j,0);
      printf("%c ",productos[j][0].clasificacion);
      printf("%d/%d ",productos[j][0].empaquetado[0],productos[j][0].empaquetado[1]);
      printf("%d/%d ",productos[j][0].caducidad[0],productos[j][0].caducidad[1]);
      printf("\n");}}
    if(productos[0][1].conttipoprod>0){printf("\nFrutas y/o verduras\n\n");
    for(j=0;j<cont1;j++){
      impresorbasico(productos,j,1);
      printf("%c ",productos[j][1].clasificacion);
      printf("%d/%d ",productos[j][1].empaquetado[0],productos[j][1].empaquetado[1]);
      printf("\n");}}
    if(productos[0][2].conttipoprod>0){printf("\nLacteos\n\n");
    for(j=0;j<cont2;j++){
      impresorbasico(productos,j,2);
      printf("%d/%d ",productos[j][2].caducidad[0],productos[j][2].caducidad[1]);
      printf("\n");}}
    if(productos[0][3].conttipoprod>0){printf("\nEnlatados\n\n");
    for(j=0;j<cont3;j++){
      impresorbasico(productos,j,3);
      printf("%d/%d ",productos[j][3].caducidad[0],productos[j][3].caducidad[1]);
      printf("%s ",productos[j][3].pasillo);
      printf("\n");}}
    if(productos[0][4].conttipoprod>0){printf("\nOtros\n\n");
    for(j=0;j<cont4;j++){
      impresorbasico(productos,j,4);
      printf("%c ",productos[j][4].clasificacion);
      printf("%s",productos[j][4].pasillo);
      printf("\n");}}
    break;
    case 7:
    exit(-1);
    break;
  }
  }while(producto!=7);
}
