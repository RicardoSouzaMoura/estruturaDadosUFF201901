/*
Q5) Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
seguida, retire o "sufixo" da cadeia s de tamanho n (isto é, retire os n últimos caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
= "abcdefghi" e n = 3, então a cadeia "abcdef" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_fim_n (char *str, int n).
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void retira_fim_n (char *str, int n);

int main(void){
    char* cadeia;
    int n;

    printf("Informe a cadeia: ");
    cadeia = (char*) malloc(sizeof(char) * 16);
    scanf(" %15[^\n]", cadeia);

    printf("Informe n: ");   
    scanf("%d", &n);

    retira_fim_n(cadeia, n);

    printf("\n");

}

void retira_fim_n(char *str, int n){
    int i,j;
    for(i = 0; str[i] != '\0'; i++);
    if (i < n){
        printf("erro");
    }
    else{
        for(j = 0; j < i-n; j++){
            printf("%c", str[j]);
        }
    }
}