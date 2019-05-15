/*
Q3) Escreva uma função que dada uma string composta por substrings separadas por “/”, retorne
todas as suas substrings da string original. Por exemplo, a string /Fla/Flu/d/ será decomposta
em:
Fla
Flu
d
Esta função não deve modificar a string original. O protótipo da função é o seguinte: 
char** s2ss (char *str)
Isto é, a resposta desta função será uma matriz de caracteres alocada
dinamicamente.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char** s2ss (char *str);

int main(void){
    char *str1 = (char*)malloc(sizeof(char) * 16);
    char **resp;

    str1 = "/Fla/Fluminense/Botaddfsfd99/";
    resp = s2ss(str1);
    int i=0;
    printf("Primeira: ");
    for(;i < 3;i++){
        char *palavra = resp[i];
        printf("%s\n", palavra);
    }

    printf("\nSegunda: ");
    str1 = "/fla/flu/botarrraxssddd/gremio/";
    resp = s2ss(str1);
    for(i=0;i < 4;i++){
        char *palavra = resp[i];
        printf("%s\n", palavra);
    }

    printf("\nTerceira: ");
    str1 = "/fla/";
    resp = s2ss(str1);
    for(i=0;i < 1;i++){
        char *palavra = resp[i];
        printf("%s\n", palavra);
    }

    printf("\nQuarta: ");
    str1 = "/a/b/";
    resp = s2ss(str1);
    for(i=0;i < 2;i++){
        char *palavra = resp[i];
        printf("%s\n", palavra);
    }
    printf("\n");
}

char** s2ss (char *str){
    int i=0;
    int qtdPalavra = 0;
    char **resp = (char**)malloc(sizeof(char*) * 1);
    int idxPalavra = 0;
    for(; str[i] != '\0'; i++){
        if (str[i] == '/') {
            if (str[i+1] != '\0'){
                qtdPalavra++;
                idxPalavra = 0;
                resp = (char **)realloc(resp, sizeof(char* ) * qtdPalavra);
                char *palavra = (char *)malloc(sizeof(char) * 1);
                resp[qtdPalavra-1] = palavra;
            }
        }
        else{
                idxPalavra++;
                char *palavra = resp[qtdPalavra-1];
                palavra = (char *)realloc(palavra, sizeof(char) * idxPalavra);
                palavra[idxPalavra-1] = str[i];
            
        }
    }
     return resp;
}