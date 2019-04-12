/*
Q1) Uma forma simples e eficiente de calcular todos os números primos até um certo valor n é o
método da Peneira de Eratosthenes. O processo é simples: escrevem-se todos os valores entre 2

e n (limite máximo). Em seguida, faz-se um círculo em volta do 2, marcando como primo e riscam-
se todos os seus múltiplos. Continua-se a fazer círculos em volta do menor inteiro que se

encontra, eliminando todos os seus múltiplos. Quando não restarem números sem terem círculos
à volta ou traços por cima, os números com círculos à volta representam todos os primos até n. A
figura seguinte apresenta o método para n = 40.

Escreva um programa que implemente a Peneira de Eratosthenes. Você deve ler o valor n e
mostrar todos os números primos encontrados.
*/

#include <stdio.h>

int main(){

    int n;
    printf("Método da Peneira de Eratosthenes\n");
    printf("Informe o limite máximo: ");
    scanf("%d", &n);

    int vet[n-1];
    int i = 0;
    for(;i < n-1; i++){
        vet[i] = i+2;
    }

    //for(i =0;i < n-1; i++){
    //    printf("%d\n", vet[i]);
    //}

    for(i = 0; i < n-1; i++){
        if (vet[i] == -1){
            continue;
        }
        int j;
        for(j = i+1; j < n-1; j++){
            if (vet[j] % vet[i] == 0){
                vet[j] = -1;
            }
        }
    }

    for(i =0;i < n-1; i++){
        if (vet[i] == -1) continue;
        printf("%d\n", vet[i]);
    }

}