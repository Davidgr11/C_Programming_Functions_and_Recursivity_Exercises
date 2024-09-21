#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int C[5][4][3], r, c, op=1, p, materia, may, alumno, grupo;
    float prom;
    srand(time(NULL));
    printf("    MENU CUBOS\n\n");
    for(p=0;p<3;p++)
    {
        for(r=0;r<5;r++)
        {
            for(c=0;c<4;c++)
            {
                C[r][c][p]=rand()%6+5;
                printf("[%d]\t", C[r][c][p]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    while(op!=0)
    {
        //system("cls");
        printf("Elige\n1)Promedio de cada alumno de todos los grupos\n");
        printf("2)Promedio de un alumno a elegir 0-4 y la materia de mayor calificación\n");
        printf("3)El alumno que tuvo mayor promedio en un grupo a elegir\n");
        printf("4)La materia que tuvo mayor promedio de un grupo a elegir\n");
        printf("5)Materia que tuvo mayor promedio de todos los grupos\n");
        printf("6)El alumno que tuvo la calificacion mas alta en una materia a elegir y un grupo a elegir\n");
        printf("0)Salir\n");
        scanf("%d", op);
        switch(op)
        {
            case 1: for(p=0;p<3;p++)
                    {
                        for(r=0;r<5;r++)
                        {
                            prom=0;
                            for(c=0;c<4;c++)
                            {
                                prom=(float)prom+C[r][c][p];
                            }
                            prom=prom/4;
                            printf("Grupo %d Alumno %d Promedio %f\n", p, r, prom);
                        }
                        printf("\n");
                    }
                    break;
            case 2: printf("Dame el alumno a calcular\n");
                    scanf("%d", &r);
                    printf("Dame el grupo del alumno\n");
                    scanf("%d", &p);
                    may=0;
                    for(c=0;c<4;c++)
                    {
                        if(C[r][c][p]>may)
                        {
                            may=C[r][c][p];
                            materia=c;
                        }
                    }
                    printf("El alumno %d tiene mayor calificación en la materia %d\n", r, materia);
                    break;
            case 3: printf("Dame el grupo que deseas calculat\n");
                    scanf("%d", &p);
                    may=0;
                    for(r=0;r<5;r++)
                    {
                        prom=0;
                        for(c=0;c<4;c++)
                        {
                            prom=(float)prom+C[r][c][p];
                        }
                        prom=prom/4;
                        printf("Alumno %d Promedio %f\n", r, prom);
                        if(prom>may)
                        {
                            may=prom;
                            alumno=r;
                        }
                    }
                    printf("El mayor promedio del grupo %p es el alumno %d\n", p, alumno);
                    break;
            case 4: printf("Ingresa el grupo que deseas calcular\n");
                    scanf("%d", &p);
                    may=0;
                    for(c=0;c<4;c++)
                    {
                        prom=0;
                        for(r=0;r<5;r++)
                        {
                            prom=prom+C[r][c][p];
                        }
                        prom=prom/5;
                        printf("Materia %d Promedio %f\n", c, prom);
                        if(prom>may)
                        {
                            may=prom;
                            materia=c;
                        }
                    }
                    printf("La materia de mayor promedio del grupo %d es la %d\n", p, materia);
                    break;
            case 5: may=0;
                    for(p=0;p<3;p++)
                    {
                        for(c=0;c<4;c++)
                        {
                            prom=0;
                            for(r=0;r<5;r++)
                            {
                                prom=(float)prom+C[r][c][p];
                            }
                        }
                        prom=prom/5;
                        if(prom>may)
                        {
                            may=prom;
                            materia=c;
                            grupo=p;
                        }
                        printf("La materia con mayor promedio en el grupo %d es la %d\n", grupo, materia);
                    }
                    break;
            case 6: printf("Ingresa el grupo que deseas evaluar\n");
                    scanf("%d", &p);
                    printf("Ingresa la materia que te interesa\n");
                    scanf("%d", &c);
                    may=0;
                    for(r=0;r<5;r++)
                    {
                        if(C[r][c][p]>may)
                        {
                            may=C[r][c][p];
                            alumno=r;
                        }
                    }
                    printf("El alumno con mayor calificacion es %d", alumno);
                    break;
            case 0: printf("Adios\n");
                    break;
            default: printf("Opcion invalida\n");
                    break;
    }
    }
    return 0;
}
