/*
Q4) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a
resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa
para quando n for menor ou igual a zero.
*/
#include <stdio.h>

int e_primo(int x);

int main(){
    int n = 1;
    printf("informe n(finalize com n<=0): ");
    scanf("%d", &n);
    for(;n > 0;){
        int x = n+1;
        for(;n > 0;){
            if (e_primo(x)){
                printf("%d ", x);
                n--;
            }
            x++;
        }

        printf("\ninforme novo n (finalize com n<=0): ");
        scanf("%d", &n);
    }
    /*if (e_primo(7)){
        printf("sim");
    }*/
    printf("\nbye !!!\n");
}

int e_primo(int x){
    int y = 1;
    int qtdDiv = 0;
    for(; y <= x ; y++){
        //printf("\ny: %d", y);
        //printf("\nx: %d", x);
        
        if (x % y == 0){
            qtdDiv++;
        }
        if (qtdDiv > 2){
            break;
        }
        //printf("\nqtdDiv: %d", qtdDiv);
    }
    //printf("\nqtdDiv: %d", qtdDiv);
    return qtdDiv == 2;
}