/*
Q6) Escreva um programa que receba, como parâmetro de entrada, uma string, e verifique se esta
string é uma “boa” senha. Entende-se por “boa” senha uma senha com as seguintes características de
formação: 
(i) ela deve possuir, no mínimo, oito caracteres; 
(ii) ela deve ter, no mínimo, um caracter entre '0' a '9'; 48-57
(iii) ela deve possuir, no mínimo, uma letra maiúscula; 65-90
(iv) ela deve ter, no mínimo, uma letra minúscula; e 97-122
(v) ela deve ter, pelo menos, um caracter do conjunto formato pelos demais
caracteres do teclado.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    char* str;
    str = (char*) malloc(sizeof(char) * 16);
    printf("Informe a senha: ");
    scanf(" %15[^\n]", str);

    int tam=0;
    int tem09, temUC, temLC, temO = 0;
    for(;str[tam] != '\0';tam++){
        int c = str[tam];
        if (c >= 48 && c <= 57){
            tem09 = 1;
        }
        else if (c >= 65 && c <= 90){
            temUC = 1;
        }
        else if (c >= 97 && c <= 122){
            temLC = 1;
        }
        else{
            temO = 1;
        }
    }
    if (tam < 8){
        printf("senha muito curta\n");
    }
    if (!tem09){
        printf("senha precisa ter pelo menos um numero\n");
    }
    if (!temLC){
        printf("senha precisa ter pelo menos um caracter minusculo\n");
    }
    if (!temUC){
        printf("senha precisa ter pelo menos um caracter maiusculo\n");
    }
    if (!temO){
        printf("senha precisa ter pelo menos um caracter especial\n");
    }

    if (tem09 && temLC && temUC && temO && tam > 8 )
      printf("senha boa\n");

    free(str);

}
