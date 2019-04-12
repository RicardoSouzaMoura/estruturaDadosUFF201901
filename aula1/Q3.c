#include <stdio.h>

int exponencial (int x, int expoente);

int main(){

    int n;
    int m;
    //int res = exponencial(4, 2);
    //printf("%d", res);
    printf("informe n(finalize com n<=0): ");
    scanf("%d", &n);
    printf("informe m(finalize com m==0 ou m==-1 ou m==1): ");
    scanf("%d", &m);
    for(;(n >= 0) && (m != 0) && (m!= -1) && (m != 1);){

        int potencia = 0;
        int expoente = 0;

        for (;potencia < n; expoente++){
            potencia = exponencial(m, expoente);
            //printf("potencia: %d: ", potencia);
            if (potencia < n){
                printf("%d ", potencia);
            }
        }
         

        printf("\ninforme n(finalize com n<=0): ");
        scanf("%d", &n);
        printf("informe m(finalize com m==0 ou m==-1 ou m==1): ");
        scanf("%d", &m);
    }
    printf("bye !!!\n");
}

int exponencial(int x, int exp){
    int i = 0;
    int result = 1;
    for(;i < exp; i++){
        result = result * x;
    }
    return result;
}