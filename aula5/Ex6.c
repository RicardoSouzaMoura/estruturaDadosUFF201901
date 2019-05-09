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

    
    free(test11);
    free(test12);
    free(test13);
    free(test14);
    free(test15);

    p = aux;
    while(p){
        p = p->prox;
        free(aux);
        aux = p;
    }
    printf("\n");
    

}

TLSE* i_p ( TLSE *l){
    if (!l || !l->prox){
        return l;
    }
    TLSE* impar = NULL;
    TLSE* fim_impar = impar;
    TLSE* par = NULL;
    TLSE* fim_par = par;
    TLSE* p = l;

    while(p){
        TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
        novo->info = p->info;
        novo->prox = NULL;
        
        if (p->info % 2 != 0){
            //impar
            if (!impar){
                impar = novo;
                fim_impar = impar;
            }
            else{
                fim_impar->prox = novo;
                fim_impar = novo;
            }

        }else{
            //par
            if (!par){
                par = novo;
                fim_par = par;
            }
            else{
                fim_par->prox = novo;
                fim_par = novo;
            }
        }
        p = p->prox;
    }

    fim_impar->prox = par;

    return impar;
    
}