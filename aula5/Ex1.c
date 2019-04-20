/*
Q1) Considerando as seguintes declarações de lista encadeada:
typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;
Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O
protótipo da função de inversão é o seguinte: void inverte (TLSE* l);
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

void inverte (TLSE* l);

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
    test12->prox = test13;
    test13->prox = test14;
    test14->prox = test15;
    test15->prox = NULL;

    TLSE *p = test11;
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }

    inverte (test11);

    printf("\n Invertida...\n");
    p = test11;
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }
    printf("\n");

}

void inverte (TLSE* l){
    TLSE *pini;
    TLSE *pfim;
    TLSE *ppre;

    if (!l || !l->prox){
        return ;
    }

    pini = l;
    pfim = pini->prox;
    while(pfim->prox){
        ppre = pfim;
        pfim = pfim->prox;
    }

    while(pini != pfim && pfim->prox != pini){
        int temp = pini->info;
        pini->info = pfim->info;
        pfim->info = temp;

        pfim = ppre;
        ppre = pini;
        while(ppre != pfim && ppre->prox != pfim){
            ppre = ppre->prox;
        }
        pini = pini->prox;
    }
}