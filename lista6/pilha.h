#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int info;
    struct no *prox;
}TNO;
typedef struct pilha{
    TNO *prim;
}TPilha;

TPilha * inicializaPilha (void);
void push (TPilha *p, int elem);
int pop (TPilha *p);
void liberaPilha (TPilha *p);
int pilhaVazia (TPilha *p);

TPilha *inicializaPilha(){
    TPilha *pilha = (TPilha*)malloc(sizeof(TPilha));
    pilha->prim = NULL;
    return pilha;
}

int pilhaVazia (TPilha *p){
    if (p){
        return p->prim == NULL;
    }
    return 0;
}

void liberaPilha(TPilha *p){
    if (!p){
        return;
    }
    while(!pilhaVazia(p)){
        pop(p);
    }
    free(p);
}

int pop(TPilha *p){
    if (pilhaVazia(p)){
        printf("Pilha vazia...\n");
        exit(1);
    }
    TNO *aux = p->prim;
    p->prim = aux->prox;
    int retorno = aux->info;
    free(aux);
    return retorno;
}

void push(TPilha *p, int elem){
    TNO* novo = (TNO*)malloc(sizeof(TNO));
    novo->info = elem;
    novo->prox = p->prim;
    p->prim = novo;
}

TPilha *mockPilha(){
    TPilha *f = inicializaPilha();
    push(f, 1);
    push(f, 2);
    push(f, 3);
    push(f, 4);
    push(f, 5);
    push(f, 6);
    return f;
}

void imprimePilha(TPilha *f){
    TNO *aux = f->prim;
    printf("\nImprimindo pilha....\n");
    while(aux){
        printf("%d", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}