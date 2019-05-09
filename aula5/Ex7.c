/*
Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void* i_p ( TLSE *l).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

TLSE* i_p ( TLSE *l);

int main(void){

    TLSE* test11 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test12 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test13 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test14 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test15 = (TLSE*)malloc(sizeof(TLSE));
    test11->info = 3;
    test12->info = 6;
    test13->info = 1;
    test14->info = 8;
    test15->info = 9;

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

    TLSE *aux = i_p(test11);

    printf("\n ocorrencias ordenadas...\n");
    p = aux;
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }
    printf("\n");

    printf("\n ocorrencias ordenadas 2...\n");
    p = test11;
    while(p){
        printf("%d", p->info);
        p = p->prox;
    }
    printf("\n");

    
    free(test11);
    free(test12);
    free(test13);
    free(test14);
    free(test15);

}

TLSE* i_p ( TLSE *l){
    if (!l || !l->prox){
        return l;
    }
    int aux = l->prox->info;
    l->prox->info = l->info;
    l->info = aux;

    return l;   
}