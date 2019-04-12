/*
Q3) Um número a é dito permutação de um número b se os dígitos de a formam uma permutação
dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação
de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.:
Considere que o dígito 0 (zero) não deve aparecer nos números.
*/

#include <stdio.h>

void myquick_sort(int *vet, int n);
void printVetor(int *vet, int n);

int main(void){

    int a, b;
    printf("Verifica se o numero A é permutacao de B\n");
    printf("Informe A e B: ");
    scanf("%d%d", &a, &b);

    // verifica qtd de digitos de A
    int contaDigitosA = 0;
    int valorTemp = a;
    do{
        valorTemp = valorTemp / 10;
        contaDigitosA++;

    } while (valorTemp > 0);

    // verifica qtd de digitos de B
    int contaDigitosB = 0;
    valorTemp = b;
    do{
        valorTemp = valorTemp / 10;
        contaDigitosB++;

    } while (valorTemp > 0);

    printf("%d %d\n", contaDigitosA, contaDigitosB);

    // if a qtd de digitos for diferente já nao é permutacao
    if (contaDigitosA != contaDigitosB){
        printf("A não é permutacao de B");
    }

    // populo dois vetores com digitos de A e B
    int vetA[contaDigitosA], vetB[contaDigitosA];
    int i;
    for(i = 0; i < contaDigitosA; i++){
        vetA[i] = a % 10;
        a = a / 10;
    }
    for(i = 0; i < contaDigitosA; i++){
        vetB[i] = b % 10;
        b = b / 10;
    }

    printVetor(vetA, contaDigitosA);
    printVetor(vetB, contaDigitosA);
    
    myquick_sort(vetA, contaDigitosA);
    printVetor(vetA, contaDigitosA);

    myquick_sort(vetB, contaDigitosA);
    printVetor(vetB, contaDigitosA);

    for(i = 0; i < contaDigitosA; i++){
        if (vetA[i] != vetB[i]){
            printf("A não é permutacao de B\n");
            return 1;
        }
    }

    printf("A é permutacao de B\n");
    return 2;

}

void printVetor(int *vet, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}

void myquick_sort(int *vet, int n){

    if (n <= 1)
      return;

    int pivo, a, b;
    a = 1;
    pivo = vet[0];
    b = n-1;

   do{
        while ( a < n && vet[a] <= pivo){
            a++;
        }
        while (vet[b] > pivo){
            b--;
        }

        //printf("a:%d, b:%d\n", a, b);

        if (a < b){
            int temp = vet[a];
            vet[a] = vet[b];
            vet[b] = temp;
            a++;
            b--;
        }
   }
    while(a <= b);
   

    int temp;
    temp = vet[b];
    vet[b] = pivo;
    vet[0] = temp;

    //printf("b:%d, n:%d\n", b, n);
    myquick_sort(vet, b);
    myquick_sort(&vet[b+1], n-b-1);

}