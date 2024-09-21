#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Al menos 1 letra es mayuscula -> regresa 1
int validaUnaMayuscula(char contrasenha[20]){
    int i;
    for(i=0; i<8; i++){//0 1 2 3 4 5 6 7
        if(isupper(contrasenha[i]) > 0) {//si hay mayuscula
            return 1;
        }
    }
    return 0;
}

//Al menos 1 letra es minuscula -> regresa 1
int validaUnaMinuscula(char contrasenha[20]){
    int i;
    for(i=0; i<8; i++){//0 1 2 3 4 5 6 7
        if(islower(contrasenha[i]) > 0) {//si hay mayuscula
            return 1;
        }
    }
    return 0;
}

int validaNumero(char pass[20]){
    int i;
    for(i=0; i<8; i++){//0 1 2 3 4 5 6 7
        if(pass[i] >= '0' && pass[i]<='9'){
            return 1;
        }
    }
    return 0;
}

int validaConsecutivo(char pass[20]){
    // mmP12345
    int i;
    for(i=0; i<8-1; i++){//0 1 2 3 4 5 6 7
        if(pass[i] - pass[i+1] == -1){// A B --> 65 66 ==-1
        //if(pass[i]+1 == pass[i+1]){
        //if(pass[i+1] - pass[i] == 1){
            return 0;
        }
    }
    return 1;
}

/*
Exactamente 8 caracteres
Al menos una may�scula
Al menos una min�scula
Al menos un n�mero
No hay 2 caracteres consecutivos (ab, 12)
*/
int validaPass(char contrasenha[20]){//mipasS40
    if(strlen(contrasenha) !=8){//Exactamente 8 caracteres
        return 0;
    }
    if(validaUnaMayuscula(contrasenha) == 0){//no hay mayusculas
        return 0;
    }
    if(validaUnaMinuscula(contrasenha) == 0){//no hay minusculas
        return 0;
    }
    if(validaNumero(contrasenha) == 0){//no hay numeros
        return 0;
    }
    if(validaConsecutivo(contrasenha) == 0){//hay 2 consecutivos
        return 0;
    }
    return 1;
}

void imprimeResultado(char pass[20]){

    if(validaPass(pass) == 1){
        printf("\nTu password es seguro y valido");
    }else{
        printf("\nTu password es inseguro y no es valido");
    }
}

int main()
{
    char pass[20];
    int x;
    printf("Escribe un password: ");
    scanf("%s",pass);

    imprimeResultado(pass);

    return 0;
}
