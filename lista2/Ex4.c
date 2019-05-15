/*
Q4) Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se
uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é
considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá
imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou
“FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o
número for negativo.
*/

#include <stdio.h>

int contaDigitos(int n);
void vetorizaNumero(int *vet, int num);
void printVetor(int *vet, int n);

int main(void){
    while(1){
        int n;
        printf("PALINDROMO\n");
        printf("Informe o numero a checar: ");
        scanf("%d", &n);
        if (n < 0){
            return 1;
        }
        int tamVet = contaDigitos(n);
        printf("tamVet: %d\n", tamVet);
        int vet[tamVet];

        vetorizaNumero(vet, n);

        printVetor(vet, tamVet);

        int i = 0;
        int j = tamVet-1;
        int e_palindromo = 1;
        while(i <= j){
            if (vet[i] == vet[j]){
                i++;
                j--;
            }
            else{
                e_palindromo = 0;
                break;
            }
        }

        !e_palindromo ? printf("FALSO\n") : printf("VERDADEIRO\n");

    }
}

int contaDigitos(int n){
    int retorno = 0;
    while (n > 0){
        n = n / 10;
        retorno++;
    }
    return retorno;
}

void vetorizaNumero(int *vet, int num){
    int i = 0;
    while(num > 0){
        vet[i] = num % 10;
        num = num / 10;
        i++;
    }
}

void printVetor(int *vet, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}
