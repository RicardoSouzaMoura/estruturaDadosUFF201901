/*
Q3) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, desloque uma vez os elementos de l, de acordo com n. Se n é ímpar, o
elemento que está na última posição passa a ser o primeiro quando a lista é deslocada.
Senão, o elemento que está na primeira posição passa a ser o último. O protótipo desta
função é o seguinte: TLSE* desloca (TLSE* l, int n).
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

TLSE* desloca (TLSE* l, int n);

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
    //test12->prox = test13;
    //test13->prox = test14;
    //test14->prox = test15;
    test12->prox = NULL;

    TLSE *p = test11;
    printf("\n printing test11...\n");
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }

    p = desloca (test11, 2);
    TLSE* aux = p;
    printf("\n Shift to left...\n");
    while(aux){
        printf("%d", aux->info);
        aux = aux->prox;
    }
    printf("\n");

    p = desloca (p, 1);
    aux = p;
    printf("\n Shift to Right...\n");
    while(aux){
        printf("%d", aux->info);
        aux = aux->prox;
    }
    printf("\n");

    free(p);
    free(aux);
    free(test11);
    free(test12);
    free(test13);
    free(test14);
    free(test15);

}

TLSE* desloca (TLSE* l, int n){

    if (!l || !l->prox){
        return l;
    }

    TLSE* retorno;
    TLSE* aux;
    if (n%2 != 0){
        aux = l;
        retorno = l->prox;
        while(retorno->prox){
            aux = retorno;
            retorno = retorno->prox;
        }
        retorno->prox = l;
        aux->prox = NULL;
    }
    else{
        retorno = l->prox;
        aux = retorno;
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = l;
        l->prox = NULL;
    }
    return retorno;
}