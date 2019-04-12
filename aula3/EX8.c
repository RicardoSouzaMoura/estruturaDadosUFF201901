/*
Q8) Escreva uma função que dadas duas strings, retorne UM se a primeira contém a segunda,
ignorando maiúsculas e minúsculas, e ZERO, caso contrário. O protótipo da função é o seguinte: 
int cic (char *str1, char *str2).
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int cic (char *str1, char *str2);
int e_igual_ic (char c1, char c2);

int main(void){
    char *str1, *str2;
    str1 = (char*)malloc(sizeof(char) * 16);
    str2 = (char*)malloc(sizeof(char) * 16);

    scanf(" %16[^\n]", str1);
    scanf(" %16[^\n]", str2);

    int retorno = cic(str1, str2);

    printf("retorno: %d", retorno);
}

int cic (char *str1, char *str2){
    int i,j = 0;
    int achouPrim = -1;
        for(j=0; str2[i] != '\0' && str1[j] != '\0';){
            if (e_igual_ic(str2[i], str1[j])){
                i++;
                if (achouPrim == -1){
                    achouPrim = j;
                }
                j++;
            }
            else{
                if (achouPrim != -1){
                    i = 0;
                    j = achouPrim+1;
                    achouPrim = -1;
                }
                else{
                    j++;
                }
            }
        }
        if (achouPrim > 0){
            return 1;
        }
        return 0;
}

int e_igual_ic (char c1, char c2){
    if (((c1 >=65 && c1<=90) || (c1 >=97 && c1<=122) ) 
        && ((c2 >=65 && c2<=90) || (c2 >=97 && c2<=122) )){
            c1 = c1 > 90 ? c1 - 32: c1;
            c2 = c2 > 90 ? c2 - 32: c2;
    }
    return c1 == c2;
}