#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//David Gonzalez y Vania Cadena

int main()
{
    char te1[4][27]={{"abcdefghijklmnopqrstuvwxyz"},{}},
         pal[10];
    int r, c, op, tabla, ok, x, i, tam;
    srand(time(NULL));
    for(r=1;r<4;r++)
    {
        tam=0;
        for(c=0;c<26;c++)
        {
            do
            {
            x=rand()%26+97;
            ok=1;
            for(i=0;i<tam && ok==1;i++)
            {
                if(x==te1[r][i])
                {
                    ok=0;
                }
            }
            }while(ok==0);
            te1[r][c]=x;
            tam++;
        }
        te1[r][26]='\0';
    }
//   IMPRIMIMOS PARA VERIFICAR TABLAS
   for(r=0;r<4;r++)
    {
        printf("%s\n", te1[r]);
    }
   do
    {
        printf("\n¿Que quieres hacer?\n\n1)ENCRIPTAR PALABRA\n2)DESENCRIPTAR PALABRA\n3)SALIR\n");
        scanf("%d", &op);
        switch(op)
        {
            case 1: printf("¿Que tabla de equivalencia quieres utilizar? (1, 2, 3)\n");
                    scanf("%d", &tabla);
                    while(tabla>3 || tabla<1)
                    {
                        printf("ERROR de rango\n\n¿Que tabla de equivalencia quieres utilizar? (1, 2, 3)\n");
                        scanf("%d", &tabla);
                    }
                    printf("Dame la palabra a encriptar\n");
                    fflush(stdin);
                    gets(pal);
                    printf("\nLa palabra encriptada con la tabla %d es:\t", tabla);
                    for(r=0;r<strlen(pal);r++)
                    {
                        for(c=0;c<27;c++)
                        {
                            if(pal[r]==te1[0][c])
                            {
                                printf("%c", te1[tabla][c]);
                            }
                        }
                    }
                    break;
            case 2: printf("¿Que tabla de equivalencia quieres utilizar? (1, 2, 3)\n");
                    scanf("%d", &tabla);
                    while(tabla>3 || tabla<1)
                    {
                        printf("ERROR de rango\n\n¿Que tabla de equivalencia quieres utilizar? (1, 2, 3)\n");
                        scanf("%d", &tabla);
                    }
                    printf("Dame la palabra a desencriptar\n");
                    fflush(stdin);
                    gets(pal);
                    printf("\nLa palabra desencriptada con la tabla %d es\t", tabla);
                    for(r=0;r<strlen(pal);r++)
                    {
                        for(c=0;c<27;c++)
                        {
                            if(pal[r]==te1[tabla][c])
                            {
                                printf("%c", te1[0][c]);
                            }
                        }
                    }
                    break;
            case 3: printf("Adios\n");
                    break;
            default: printf("Error, opción inválida\n");
                    break;
        }

    }while(op!=3);
    return 0;
}
