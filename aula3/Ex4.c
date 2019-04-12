/*
Q4) Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
seguida, retire o "prefixo" da cadeia s de tamanho n (isto é, retire os n primeiros caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
= "abcdefghi" e n = 3, então a cadeia "defghi" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_inicio_n (char *str, int
n).
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void retira_inicio_n (char *str, int n);

int main(void){
    char* cadeia;
    int n;

    printf("Informe a cadeia: ");
    cadeia = (char*) malloc(sizeof(char) * 16);
    scanf(" %15[^\n]", cadeia);

    printf("Informe n: ");   
    scanf("%d", &n);

    retira_inicio_n(cadeia, n);

    printf("\n");

}

void retira_inicio_n(char *str, int n){
    int i;
    for(i = 0; str[i] != '\0'; i++);
    if (i < n){
        printf("erro");
    }
    else{
        for(i = n; str[i] != '\0'; i++){
            printf("%c", str[i]);
        }
    }
}