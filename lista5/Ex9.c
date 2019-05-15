/*
Q9) Considerando a definição de lista de Q1, escreva uma função em C que, dadas duas
listas, faça a concatenação das mesmas ao final de l1. O protótipo da função é o seguinte:
TLSE* junta_listas (TLSE* l1, TLSE* l2).
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

TLSE* junta_listas (TLSE* l1, TLSE* l2);
void imprime(TLSE *l);

int main(void){
    TLSE* test11 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test12 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test13 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test14 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test15 = (TLSE*)malloc(sizeof(TLSE));
    test11->info = 1;
    test12->info = 2;
    test13->info = 3;
    test14->info = 4;
    test15->info = 5;

    test11->prox = test12;
    test12->prox = NULL;
    test13->prox = test14;
    test14->prox = test15;
    test15->prox = NULL;

    TLSE* p = junta_listas(test11, test13);

    imprime(p);
    printf("\n");
    imprime(test11);
    printf("\n");
    imprime(test13);

    free(test11);
    free(test12);
    free(test13);
    free(test14);
    free(test15);
}

void imprime(TLSE *l){
    TLSE *temp = l;
    while(temp){
        printf("%d\n", temp->info);
        temp = temp->prox;
    }
}

TLSE* junta_listas (TLSE* l1, TLSE* l2){
    TLSE *retorno = l1;
    TLSE *aux = retorno;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = l2;

    return retorno;
}