/*
Q9) Escreva uma função que dadas duas strings, retorne UM se as strings são iguais, ignorando
maiúsculas e minúsculas, e ZERO, caso contrário. O protótipo da função é o seguinte: 
int igual (char *str1, char *str2).
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int igual (char *str1, char *str2);
int e_igual_ic (char c1, char c2);

int main(void){
    char *str1, *str2;
    str1 = (char*)malloc(sizeof(char) * 16);
    str2 = (char*)malloc(sizeof(char) * 16);

    str1 = "ABcdEFDAd1";
    str2 = "ABcdEFDAD1";

    //printf("%s%s", str1, str2);

    int retorno = igual(str1, str2);

    printf("retorno: %d\n", retorno);
}

int igual (char *str1, char *str2){

    if (str1[0] == '\0' && str2[0] == '\0'){
        return 1;
    }
    if (str1[0] == '\0' && str2[0] != '\0'){
        return 0;
    }
    if (str1[0] != '\0' && str2[0] == '\0'){
        return 0;
    }

    if (e_igual_ic(str1[0], str2[0])){
        return 1 && igual(&str1[1], &str2[1]);
    }
    else{
        return 0;
    }
    
}

int e_igual_ic (char c1, char c2){
    if (((c1 >=65 && c1<=90) || (c1 >=97 && c1<=122) ) 
        && ((c2 >=65 && c2<=90) || (c2 >=97 && c2<=122) )){
            c1 = c1 > 90 ? c1 - 32: c1;
            c2 = c2 > 90 ? c2 - 32: c2;
    }
    return c1 == c2;
}