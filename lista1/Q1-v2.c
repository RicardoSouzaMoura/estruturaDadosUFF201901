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
    while(n> 0){
        scanf("%d", &n);
        int i = 0; int vet[n]; int j=0;
        for(; i < n; i++){
            scanf("%d", &vet[i]);
        }
        int maior = 1; int temp=1;
        for(i=0; i<n;i++){
            for(j=i+1; j<n; j++){
                if(vet[j] >= vet[i]){
                    temp++;
                    i++;
                }
                else{
                    if (temp > maior){
                        maior = temp;
                        temp = 1;
                    }
                    else{
                        temp = 1;
                    }
                    break;
                }
            }
            if (j >=n){
                if (temp > maior){
                    maior = temp;
                }
                break;
            } 
        }
        printf("Comprimento Maximo: %d \n", maior);
        printf("informe novo n (finalize com n<=0): ");
             
    }
    printf("bye !!!\n");
}