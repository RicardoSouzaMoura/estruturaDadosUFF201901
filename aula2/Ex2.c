/*
Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um
vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3xˆ2 + 2x + 12 terá um
vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio 
xˆ3 + xˆ2 + 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve,
infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b)
calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios
na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero.
*/

#include <stdio.h>

int main(void){

    printf("Integra e deriva polinômios.\n");
    int g;
    while(1){
        printf("Informe o maior grau do polinomio e seus coeficientes: ");
        scanf("%d", &g);
        if (g <= 0) return 1;
        int i = 0;
        int coef[g + 1];
        for(; i < g + 1; i++){
            scanf("%d", &coef[i]);
        }

        // imprime coeficientes
        printf("{");
        for(i=0;i < g + 1; i++){
            printf("%d", coef[i]);
            if (i + 1 < g + 1){
                printf(", ");
            }
        }
        printf("}\n");

        // imprime integral
        printf("{0, ");
        for(i = 0; i < g + 1; i++){
            if (i == 0){
               printf("%d", coef[i]); 
            }
            else{
              if (coef[i] > 0)
                printf("%d", 1);
              else {
                printf("%d", 0); 
              }
            }
            if (i + 1 < g + 1){
                printf(", ");
            }
        }
        printf("}\n");

        //imprime derivada
        printf("{");
        for(i = 1; i < g + 1; i++){
            printf("%d", coef[i]*i);
            if (i + 1 < g + 1){
                printf(", ");
            }
        }
        printf("}\n");
    }
}