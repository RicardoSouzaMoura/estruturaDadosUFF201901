#include <stdlib.h>
#include <stdio.h>

typedef struct nof{
    int info;
    struct nof *prox;
}TNOF;

typedef struct fila {
    TNOF *ini, *fim;
}TFila;
TFila* inicializaFila (void);
TFila* insere (TFila *f, int elem);
int retira (TFila *f);
void liberaFila (TFila *f);
int filaVazia (TFila *f);
TFila *mockFila();
void imprimeFila(TFila *f);

TFila *inicializaFila(){
    TFila *fila = (TFila*)malloc(sizeof(TFila));
    fila->fim = NULL;
    fila->ini = NULL;
    return fila;
}

TFila * insere(TFila *f, int elem){
    TNOF *novo = (TNOF*)malloc(sizeof(TNOF));
    novo->info = elem;
    novo->prox = NULL;
    if (!f){
        f = inicializaFila();
    }
    if (filaVazia(f)){
        f->ini = novo;
        f->fim = novo;
    }
    else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int retira (TFila *f){
    if (filaVazia(f)){
        printf("Fila vazia...\n");
        exit(1);
    }
    int ret = f->ini->info;
    TNOF* aux = f->ini;
    f->ini = f->ini->prox;
    if (!f->ini){
        f->fim = NULL;
    }
    free(aux);
    return ret;
}

void liberaFila (TFila *f){
    while (!filaVazia){
        retira(f);
    }
    free(f);
}

int filaVazia(TFila *f){
    return (!f || !f->ini);
}

TFila *mockFila(){
    TFila *f = inicializaFila();
    f = insere(f, 1);
    f = insere(f, 2);
    f = insere(f, 3);
    f = insere(f, 4);
    f = insere(f, 5);
    f = insere(f, 6);
    return f;
}

void imprimeFila(TFila *f){
    TNOF *aux = f->ini;
    printf("\nImprimindo fila....\n");
    while(aux){
        printf("%d", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}