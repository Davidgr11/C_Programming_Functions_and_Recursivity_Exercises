#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

//escribe las palabras del juego
void llenaPalabras(char palabra[3][5][10]){
    strcpy(palabra[0][0], "perro");
    strcpy(palabra[0][1], "gato");
    strcpy(palabra[0][2], "elefante");
    strcpy(palabra[0][3], "canario");
    strcpy(palabra[0][4], "perico");

    strcpy(palabra[1][0], "francia");
    strcpy(palabra[1][1], "mexico");
    strcpy(palabra[1][2], "italia");
    strcpy(palabra[1][3], "escocia");
    strcpy(palabra[1][4], "finlandia");//deben tener m�ximo 9 letras, porque mi arreglo solo guarda 10

    strcpy(palabra[2][0], "mandarina");
    strcpy(palabra[2][1], "margarita");
    strcpy(palabra[2][2], "pera");
    strcpy(palabra[2][3], "sandia");
    strcpy(palabra[2][4], "lavanda");
}

int adivina(char palabra[10],char letra, char oculta[10], int vidas);

int main(){
    /* Para el juego necesito:
        3 categorias 5 palabras
        5 vidas
        palabra oculta (guiones)
        letra que adivino
    */

    //[categoria][palabra][letras]
    char palabra[3][5][10];
    int vidas;
    char oculta[10], letra;
    int i, cat, pal, tam;

    srand(time(NULL));
    llenaPalabras(palabra);//se llena dentro de la funci�n y al salir est� lleno

    vidas=5;//vidas iniciales
    for(i=0; i<10; i++){//llenar palabra de respuesta en "vac�os"
        oculta[i]='\0';
    }

    printf("Que categoria quieres? 1,2,3");
    scanf("%d", &cat );
    cat--;// categor�a elegida: 0 1 o 2
    pal = rand()%5;//5 palabras aleatorias, de 0 a 4

    //palabra[cat][pal]; <- palabra elegida
    tam = strlen(palabra[cat][pal]);

    do{
        printf("Vidas: %d\n", vidas);

        for(i=0; i<tam; i++){
            if(oculta[i] == '\0'){//si no he adivinado la letra, sale un _
                printf("_ ");
            }else{//ya la adivin� sale la letra
                printf("%c ", oculta[i]);
            }
        }
        printf("\nQue letra quieres adivinar?");
        fflush(stdin);//limpia el buffer del teclado, si no est�, asume que ya se ley� una letra
        scanf("%c", &letra);
        letra = tolower(letra);//cambiarla a min�scula para que siempre la encuentre en la palabra

        vidas = adivina(palabra[cat][pal], letra, oculta, vidas);//funci�n que adivina la palabra

    }while(vidas > 0 && strcmp(palabra[cat][pal], oculta) !=0 );//se repite mientras tenga vidas y las palabras sean diferentes (las 2 cosas al mismo tiempo)

    if(vidas > 0){//sal� del cilo y tengo vidas
        printf("Ganaste!");
    }else{//sal� y no tengo vidas
        printf("Perdiste, la palabra era: %s", palabra[cat][pal]);
    }

    return 0;
}

/*
Recibe:
    la palabra que estoy adivinando
    la letra que escrib� que quiero adivinar
    la palabra oculta, porque si est�, la debo de colocar ah�
    las vidas, para saber cu�ntas tengo, y si fallo quitar una
Regresa
    las nuevas vidas, si est� bien quedan igual, si est� mal, cambian
*/

int adivina(char palabra[10],char letra, char oculta[10], int vidas){
    int tam, i;
    int quitaVidas;
    tam = strlen(palabra);//tama�o de la palabra que estoy adivinando
    /*
    perro
    r
    __rr_
    */
    quitaVidas = 1;//bandera, quito vidas o no?
    for(i=0; i<tam; i++){//b�squeda lineal, letra por letra
        if(letra == palabra[i]){//si es la que busco, la guardo en la palabra oculta en la misma posici�n
            oculta[i] = letra;
            quitaVidas = 0;//encontrpe al menos una letra! entonces no quita vidas
        }
    }
    if(quitaVidas == 1){//no encontr� letras (no cambi� a 0), quita una vida
        vidas--;
    }
    return vidas;
}
