/*
Q5) Considerando a definição de lista de Q1, escreva uma função em C que remova
todas as ocorrências de um elemento numa lista. Seu protótipo O protótipo desta função é
o seguinte: TLSE* rto (TLSE* l, int elem).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

TLSE* rto (TLSE* l, int elem);


int main(void){

    TLSE* test11 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test12 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test13 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test14 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test15 = (TLSE*)malloc(sizeof(TLSE));
    test11->info = 2;
    test12->info = 1;
    test13->info = 1;
    test14->info = 1;
    test15->info = 3;

    test11->prox = test12;
    test12->prox = test13;
    test13->prox = test14;
    test14->prox = test15;
    test15->prox = NULL;

    TLSE *p = test11;
    printf("\n lista inteira...\n");
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }

    TLSE *aux = rto(test11, 1);

    printf("\n ocorrencias removidas...\n");
    p = aux;
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }
    printf("\n");

    free(aux);
    free(test11);
    free(test12);
    free(test13);
    free(test14);
    free(test15);

}

TLSE* rto (TLSE* l, int elem){
    if (!l){
        return l;
    }
    TLSE* retorno;
    if (l->info == elem){
        return rto(l->prox, elem);
    }
    else{
        retorno = (TLSE*)malloc(sizeof(TLSE));
        retorno->info = l->info;
        retorno->prox = rto(l->prox, elem);
        return retorno;
    }

    return retorno;

}