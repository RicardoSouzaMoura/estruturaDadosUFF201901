/*
Q6) Considerando a definição de lista de Q1, escreva uma função em C que, dada uma
lista l qualquer, retorne, numa lista de saída, os elementos ímpares e os elementos pares
da lista l, na ordem em que os elementos aparecem em l. Ao final da execução desta
função, a lista resultante terá todos os elementos da lista l (primeiro os ímpares, depois os
pares, na ordem em que eles aparecem em l), e a lista l continuará contendo os seus
elementos. O protótipo da função é o seguinte: TLSE* i_p ( TLSE *l).
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

    TLSE *aux = i_p(test11);

    printf("\n ocorrencias ordenadas...\n");
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

TLSE* i_p ( TLSE *l){
    if (!l || !l->prox){
        return l;
    }
    TLSE* impar;
    TLSE* par;
    TLSE* p = l;

    while(p){
        if (p->info % 2 != 0){
            //impar

            TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
            novo->info = l->info;
            novo->prox = NULL;

        }else{
            //par

        }
    }
    
    
}