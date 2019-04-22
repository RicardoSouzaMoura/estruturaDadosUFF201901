/*
Q2) Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
alterada. O protótipo da função de inversão é o seguinte: TLSE* inverte (TLSE* l).
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

TLSE* inverte (TLSE* l);

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
    //test15->info = 5;

    test11->prox = test12;
    test12->prox = test13;
    test13->prox = test14;
    //test14->prox = test15;
    test14->prox = NULL;

    TLSE *p = test11;
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }

    p = inverte (test11);

    printf("\n Invertida...\n");
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }
    printf("\n");

    printf("\n Original...\n");
    p = test11;
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }
    printf("\n");

}

TLSE* inverte (TLSE* l){
    if (!l || !l->prox){
        return l;
    }

    TLSE* retorno;
    // apenas dois elementos
    TLSE* p = l;
    while(p){
        TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
        novo->info = p->info;
        novo->prox = retorno;
        retorno = novo;
        p = p->prox;
    }

    return retorno;

}