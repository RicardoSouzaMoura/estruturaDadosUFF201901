/*
Q5) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste
programa deve ser “1100”. Seu programa para quando n for menor que zero.
*/
#include <stdio.h>

void printBinario(int x);

int main(){
    int n = 1;
    printf("informe n(finalize com n<0): ");
    scanf("%d", &n);
    for(;n >= 0;){
        printBinario(n);
        printf("\ninforme novo n (finalize com n<=0): ");
        scanf("%d", &n);
    }

    printf("\nbye !!!\n");
}

void printBinario(int num){
    if (num >= 2){
        int y = num % 2;
        printBinario(num/2);
        printf("%d",y);
    }
    else{
        printf("%d", num);
    }
}