/*
Q1) Escreva um programa que, infinitamente, leia um número inteiro n, que representa o tamanho,
seguida de uma sequência de n números inteiros, e determine o comprimento máximo de um
segmento crescente destes n números. Exemplos:
 Na sequência 5, 10, 3, 2, 4, 7, 9, 8, 5 o comprimento do segmento crescente máximo é 4.
 Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.
Seu programa para quando n for menor ou igual a zero.
*/
#include <stdio.h>

int main(){

    int n = 1;
    printf("informe n(finalize com n<=0): ");
    scanf("%d", &n);
    for(;n > 0;){
        int compMax = 1;
        int compMaxTemp = 0;
        int itemSeq = 0;
        int itemSeqTemp = 0;
        for(;n > 0;n--){
            scanf("%d", &itemSeqTemp);
            //printf("itemSeqTemp/itemSeq %d/%d\n", itemSeqTemp, itemSeq);
            if (itemSeqTemp > itemSeq){
                compMaxTemp++;
            }
            else{
                if (compMaxTemp > compMax){
                    compMax = compMaxTemp;
                }
                compMaxTemp = 1;
            }
            itemSeq = itemSeqTemp;
        }
        if (compMaxTemp > compMax){
            compMax = compMaxTemp;
        }
        printf("Comprimento Maximo: %d \n", compMax);
        printf("informe novo n (finalize com n<=0): ");
        scanf("%d", &n);
    }
    printf("bye !!!\n");
}