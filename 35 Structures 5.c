#include <stdio.h>
#include <stdlib.h>

struct fechan
{
    char dia[3];
    char mes[3];
    char anio[5];
};typedef struct fechan F;

struct nombrec
{
    char np[20];
    char app[20];
    char apm[20];
};typedef struct nombrec N;


struct direccioc
{
    char calle[20];
    int num;
    char col[20];
};typedef struct direccioc D;

struct cuentas
{
    int numcta;
    float saldo;
    char tipo[20];
};typedef struct cuentas C;

struct persona
{
    N nombre;
    int edad;
    char edo_civil[20];
    D direccion;
    N referencia;
    F cumple;
    char rfc[11];
    float saldoT;
    C vctas[3];
};typedef struct persona P;

void llena (P [10],int *);
void imprime (P [10],int );
P busca_nombre (P [10],int,N);
void imprimeUna(P);
D busca_direccion(P[10],int,N);
void calcularrfc(N,F,char[11]);
void busca_rfc(P[10],int,N,char[11]);
void ordena (P[10],int);
float saldo_total(C [3]);

int main()
{
    P vectorP[10],personaE;
    int opc,dir=0;
    N nombreB;
    D direccionE;
    char rfcE[11];
    printf("Manejo de Estructuras \n");
    do
    {
        printf("\n 1. Llenar \n 2. Imprimir \n 3. Buscar por nombre \n 4. Buscar direccion \n 5. Buscar RFC de una persona\n 0. Salir");
        scanf("%d",&opc);
        switch(opc)
        {
            case 1: llena (vectorP,&dir);
            break;
            case 2: ordena(vectorP,dir);
                imprime(vectorP,dir);
            break;
            case 3:printf("\n Ingresa el nombre completo de persona a buscar ");
                fflush(stdin);
                gets(nombreB.np);
                fflush(stdin);
                gets(nombreB.app);
                fflush(stdin);
                gets(nombreB.apm);
                personaE=busca_nombre(vectorP,dir,nombreB);
                if (personaE.edad!=0)
                    imprimeUna(personaE);
                else
                    printf("\n No existe esa persona");
                break;
            case 4:printf("\n Ingresa el nombre completo de persona a buscar ");
                fflush(stdin);
                gets(nombreB.np);
                fflush(stdin);
                gets(nombreB.app);
                fflush(stdin);
                gets(nombreB.apm);
                direccionE=busca_direccion(vectorP,dir,nombreB);
                if (direccionE.num!=0)
                    printf("\n Direccion %s %d %s",direccionE.calle,direccionE.num,direccionE.col);
                else
                    printf("\n No existe esa persona");
                break;
            case 5:printf("\n Ingresa el nombre completo de persona a buscar ");
                fflush(stdin);
                gets(nombreB.np);
                fflush(stdin);
                gets(nombreB.app);
                fflush(stdin);
                gets(nombreB.apm);
                busca_rfc(vectorP,dir,nombreB,rfcE);
                if (strcmp(rfcE,"\0")!=0)
                    printf("\n El RFC es %s",rfcE);
                else
                    printf("\n No existe la persona ");
                break;

            case 0:printf("\n Adios");
         }
    }while (opc!=0);
    return 0;
}

void ordena (P vecP[10],int dir)
{
    int i,j;
    P aux;
    for (i=0;i<dir;i++)
    {
        for (j=0;j<dir-1;j++)
        {
            if (strcmp(vecP[j].nombre.app,vecP[j+1].nombre.app)>0)
              {
                  aux=vecP[j];
                  vecP[j]=vecP[j+1];
                  vecP[j+1]=aux;
              }
        }
    }
}

void busca_rfc(P vecP[10],int dir, N nomB,char rfcE[11])
{
    int i=0;

    while (i<dir && (strcmp(nomB.np,vecP[i].nombre.np)!=0  || strcmp(nomB.app,vecP[i].nombre.app)!=0 ))
        i++;
    if (i!=dir)
     strcpy(rfcE,vecP[i].rfc);
    else
     strcpy (rfcE,"\0");
}

D busca_direccion (P vecP[10],int dir,N nomB)
{
    int i=0;
    D estvacia={NULL};
    while (i<dir && (strcmp(nomB.np,vecP[i].nombre.np)!=0  || strcmp(nomB.app,vecP[i].nombre.app)!=0 ))
        i++;
    if (i!=dir)
        return (vecP[i].direccion);
    else
        return estvacia;
}


void imprimeUna(P personaE)
{
    int j;
    printf("\n\n%s %s %s %d  %s",personaE.nombre.np,personaE.nombre.app,personaE.nombre.apm,personaE.edad,personaE.edo_civil);
    printf("\n\t\t Direccion :%s %d %s",personaE.direccion.calle,personaE.direccion.num,personaE.direccion.col);
    printf("\n\t\t Referencia %s  %s  %s",personaE.referencia.np,personaE.referencia.app,personaE.referencia.apm);
    printf("\n\t\t Fecha de Nacimiento %d %s %s \t RFC %s",personaE.cumple.dia,personaE.cumple.mes,personaE.cumple.anio,personaE.rfc);
    printf("\n\t\t CUENTAS");
   for (j=0;j<3;j++)
        {
            printf("\n\t\t\t\tNumero de cuta %d Saldo %f %s",personaE.vctas[j].numcta,personaE.vctas[j].saldo,personaE.vctas[j].tipo);

        }
     printf("\n\t\t\t\t Saldo Total  %f",personaE.saldoT);
}

P busca_nombre(P vecP[10],int dir,N nomB)
{
    int i=0;
    P estvacia={NULL};
    while (i<dir && (strcmp(nomB.np,vecP[i].nombre.np)!=0  || strcmp(nomB.app,vecP[i].nombre.app)!=0 ))
        i++;
    if (i!=dir)
        return (vecP[i]);
    else
        return estvacia;
}

void llena (P vecP[10],int *dir)
{
    int i;
    if (*dir <10)
    {
        printf("\n Ingresa el nombre Propio");
        fflush(stdin);
        gets(vecP[*dir].nombre.np);
        printf("\n Ingresa el Apellido Paterno");
        fflush(stdin);
        gets(vecP[*dir].nombre.app);
        printf("\n Ingresa el Apellido Materno");
        fflush(stdin);
        gets(vecP[*dir].nombre.apm);
        printf("\n Edad");
        scanf("%d",&vecP[*dir].edad);
        printf("\n Edo civil ");
        fflush(stdin);
        gets(vecP[*dir].edo_civil);
        printf("\n Ingresa tu direccion Calle");
        fflush(stdin);
        gets(vecP[*dir].direccion.calle);
        printf("\n Numero");
        scanf("%d",&vecP[*dir].direccion.num);
        printf("\n Colonia");
        fflush(stdin);
        gets(vecP[*dir].direccion.col);
        printf("\n Ingresa el nombre Propio de Referencia");
        fflush(stdin);
        gets(vecP[*dir].referencia.np);
        printf("\n Ingresa el Apellido Paterno de Referencia");
        fflush(stdin);
        gets(vecP[*dir].referencia.app);
        printf("\n Ingresa el Apellido Materno de Referencia");
        fflush(stdin);
        gets(vecP[*dir].referencia.apm);
        printf("\n Dia de Nacimiento ");
        fflush(stdin);
        gets(vecP[*dir].cumple.dia);
         printf("\n Mes de Nacimiento ");
        fflush(stdin);
        gets(vecP[*dir].cumple.mes);
          printf("\n Anio de Nacimiento ");
        fflush(stdin);
        gets(vecP[*dir].cumple.anio);
        calcularrfc(vecP[*dir].nombre,vecP[*dir].cumple,vecP[*dir].rfc);
        printf("\n Datos de las cuentas");
        for (i=0;i<3;i++)
        {
            printf("\n Ingresa el num. de Cta");
            scanf("%d",&vecP[*dir].vctas[i].numcta);
            printf("\n Saldo de la cuenta");
            scanf("%f",&vecP[*dir].vctas[i].saldo);
            printf("\n Tipo de cuenta (debito/credito)");
            fflush(stdin);
            gets(vecP[*dir].vctas[i].tipo);
            strupr(vecP[*dir].vctas[i].tipo);
        }
        vecP[*dir].saldoT=saldo_total(vecP[*dir].vctas);
        *dir=*dir+1;
        //(*dir)++;
    }
    else
        printf("\n Arreglo lleno");
}

float saldo_total(C vc[3])
{
    int i;
    float total=0;
    for (i=0;i<3;i++)
    {
        if (strcmp(vc[i].tipo,"DEBITO")==0)
            total=total+vc[i].saldo;
        else
            total=total-vc[i].saldo;
    }
    return (total);
}

void calcularrfc(N name,F cumplex,char rfc[11])
{
   strncpy(rfc,name.app,2);
   strncat(rfc,name.apm,1);
   strncat(rfc,name.np,1);
   rfc[4] =cumplex.anio[2];
   rfc[5] =cumplex.anio[3];
   rfc[6] ='\0';
   strcat(rfc,cumplex.mes);
   strcat(rfc,cumplex.dia);
}

void imprime (P vecP[10],int dir)
{
    int i,j;
    for (i=0;i<dir;i++)
    {
        printf("\n %s %s %s %d %s ",vecP[i].nombre.np,vecP[i].nombre.app,vecP[i].nombre.apm,vecP[i].edad,vecP[i].edo_civil);
        printf("\n\t\t Direccion :%s %d %s",vecP[i].direccion.calle,vecP[i].direccion.num,vecP[i].direccion.col);
        printf("\n\t\t Referencia %s %s %s",vecP[i].referencia.np,vecP[i].referencia.app,vecP[i].referencia.apm);
        printf("\n\t\t Fecha de Nacimiento %d %s %s \t RFC %s",vecP[i].cumple.dia,vecP[i].cumple.mes,vecP[i].cumple.anio,vecP[i].rfc);
        printf("\n\t\t CUENTAS");
        for (j=0;j<3;j++)
        {
            printf("\n\t\t\t\tNumero de cuta %d Saldo %f %s",vecP[i].vctas[j].numcta,vecP[i].vctas[j].saldo,vecP[i].vctas[j].tipo);

        }
        printf("\n\t\t\t\t Saldo Total  %f",vecP[i].saldoT);
    }

}
