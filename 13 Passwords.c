#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//David González
int main()
{
    char pass[9];
    int x, i, min, may, band=0;
    printf("Escribe una contraseña y el programa validara su seguridad\n\n");
    printf("Requerimientos para contraseña segura:\n8 caracteres\nAl menos una mayuscula\nAl menos una minuscula\nAl menos un numero\nNo caracteres consecutivos\n\n");
    do
    {
        printf("\nINGRESA\n");
        gets(pass);
        x=strlen(pass);
        if(x==8)
        {
            min=0;
            may=0;
            for(i=0;i<9;i++)
            {
                if(islower(pass[i])>0)
                {
                    min++;
                }
                if(isupper(pass[i])>0)
                {
                    may++;
                }
            }
            if(min>0)
            {
                if(may>0)
                {
                    //Ya no supe como validar el numero :(
                    band=1;
                }
                else
                {
                    printf("Error, no tiene ninguna mayuscula\n");
                }
            }
            else
            {
                printf("Error, no tiene ninguna minuscula\n");
            }
        }
        else
        {
            printf("Error, numero de caracteres incorrecto\n");
        }
    }while(band==0);
    return 0;
}
