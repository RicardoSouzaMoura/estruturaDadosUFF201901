/*
Q3) Considere que você receba um vetor de inteiros com números ímpares e pares e um número n,
sendo n o tamanho do vetor. Implemente uma função que separe os valores inteiros de um vetor em
ímpares e pares, obedecendo a ordem de entrada destes números no vetor. Implemente os dois
protótipos abaixo:
a) int* transf_i_p (int *vet, int n)
b) void transf_i_p (int *vet, int n)
*/

#include <stdio.h>
#include <stdlib.h>

int* transf_i_p (int *vet, int n);
void transf_i_p2 (int *vet, int n);

int main(void){
    int *vet, *vet2;
    int num;
    int n,m;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int*) malloc(sizeof(int) * n);
    vet2 = (int*) malloc(sizeof(int) * n);

    printf("Informe o numero: ");
    scanf("%d", &num);

    m = n;
    while(num > 0){
        int k = num % 10;
        num = num / 10;
        vet[m-1] = k;
        vet2[m-1] = k;
        m--;
    }

    int i = 0;
    for(;i < n; i++){
        printf("%d,", vet[i]);
    }

    printf("\n");

    vet = transf_i_p(vet, n);
    
    for(i = 0;i < n; i++){
        printf("%d,", vet[i]);
    }
    printf("\n");

    transf_i_p2(vet2, n);
    
    for(i = 0;i < n; i++){
        printf("%d,", vet2[i]);
    }
    printf("\n");
}

int* transf_i_p (int *vet, int n){
    int i,j,k = 0;
    for(; i < n; i++){
        if (vet[i] % 2 == 0){
            for(j=i+1; j < n; j++){
                if (vet[j] % 2 != 0){
                    int impar = vet[j];
                    for(k=j-1; k>=i; k--){
                        vet[k+1] = vet[k];
                    }
                    vet[i] = impar;
                    break;
                }
            }
            if (j >= n){
                break;
            }
        }
    }
    return vet;
}
void transf_i_p2 (int *vet, int n){

    vet = transf_i_p(vet, n);

    /*int i,j,k = 0;
    for(; i < n; i++){
        if (vet[i] % 2 == 0){
            for(j=i+1; j < n; j++){
                if (vet[j] % 2 != 0){
                    int impar = vet[j];
                    for(k=j-1; k>=i; k--){
                        vet[k+1] = vet[k];
                    }
                    vet[i] = impar;
                    break;
                }
            }
            if (j >= n){
                break;
            }
        }
    }*/

}