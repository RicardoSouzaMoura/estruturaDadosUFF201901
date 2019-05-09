#include <stdlib.h>
#include <stdio.h>

typedef struct lista {
    int info;
    struct lista *prox;
} TLSE;

void imprime(TLSE *l);
void muda(TLSE *l);

int main(void){
    TLSE *l1 = (TLSE*)malloc(sizeof(TLSE));
    l1->info = 1;
    TLSE *l2 = (TLSE*)malloc(sizeof(TLSE));
    l2->info = 2;
    TLSE *l3 = (TLSE*)malloc(sizeof(TLSE));
    l3->info = 3;
    
    l1->prox = l2;
    l2->prox = l3;
    l3->prox = NULL;

    imprime(l1);
    muda(l1);
    imprime(l1);

    free(l3);
    free(l2);
    free(l1);
}

void imprime(TLSE *l){
    TLSE *temp = l;
    while(temp){
        printf("%d\n", temp->info);
        temp = temp->prox;
    }
}

void muda(TLSE *l){
    TLSE *aux = l->prox;
    l->prox->prox->prox = aux;
    l->prox = l->prox->prox;
    aux->prox = NULL;
    //imprime(l);
}