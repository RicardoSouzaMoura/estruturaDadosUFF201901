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