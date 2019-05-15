/*
Q11) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, ordene os elementos de l em uma outra lista de saída. Portanto, a lista de
entrada não pode ser alterada. O protótipo da função desta função é o seguinte: TLSE *
ordena (TLSE* l).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

TLSE * ordena (TLSE* l);
TLSE * insere_ord(TLSE* lista, int info);
void imprime(TLSE *l);

int main(void){
    TLSE* test11 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test12 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test13 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test14 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test15 = (TLSE*)malloc(sizeof(TLSE));
    test11->info = 5;
    test12->info = 4;
    test13->info = 7;
    test14->info = 2;
    test15->info = 1;

    test11->prox = test12;
    test12->prox = test13;
    test13->prox = test14;
    test14->prox = test15;
    test15->prox = NULL;

    printf("\n lista entrada...\n");
    imprime(test11);

    TLSE *p = ordena (test11);

    printf("\n lista depois da ordenacao...\n");
    imprime(test11);

    printf("\n lista ordenada...\n");
    imprime(p);
    printf("\n");

    free(p);
    free(test11);
    free(test12);
    free(test13);
    free(test14);
    free(test15);
}

TLSE * ordena (TLSE* l){
    if (!l){
        return l;
    }
    TLSE *aux = l;
    TLSE *retorno = NULL;
    while(aux){
        retorno = insere_ord(retorno, aux->info);
        aux = aux->prox;
    }
    return retorno;
}

TLSE * insere_ord(TLSE* lista, int info){
    TLSE *novo = (TLSE*)malloc(sizeof(TLSE));
    novo->info = info;
    novo->prox = NULL;
    
    if (!lista){   
        return novo;
    }

    if (lista->info > info){
        novo->prox = lista;
        return novo;
    }
    
    TLSE *aux = lista->prox;
    TLSE *pre = lista;
    while(aux && aux->info < info){
        pre = aux;
        aux = aux->prox;
    }
    novo->prox = aux;
    pre->prox = novo;
    
    return lista;
}

void imprime(TLSE *l){
    TLSE *temp = l;
    while(temp){
        printf("%d", temp->info);
        temp = temp->prox;
    }
}