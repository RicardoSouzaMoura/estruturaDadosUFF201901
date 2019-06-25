/*
Dada uma ABB e uma informacao, retorne a lista de ancestrais desta informacao
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct lista_se{
    int info;
    struct lista_se *prox;
} TLSE;

typedef struct a_bin_busca{
    int info;
    struct a_bin_busca *dir;
    struct a_bin_busca *esq;
} TABB;

TLSE *ancestrais (TABB *a, int x);
TLSE *AA(TABB *a, int x);
TABB *busca(TABB *a, int x);
TLSE *ins_ini(TLSE *a, int x);
TABB *ins_TABB(TABB *a, int x);
void libera_TABB(TABB *a);
void print_TLSE(TLSE *l);
void libera_TLSE(TLSE *l);

int main(void){
    printf("inserindo...10\n");
    TABB *a = ins_TABB(NULL, 10);
    printf("inserindo...5\n");
    a = ins_TABB(a, 5);
    a = ins_TABB(a, 14);
    a = ins_TABB(a, 7);
    a = ins_TABB(a, 3);
    a = ins_TABB(a, 6);

    printf("ancestrais...\n");
    TLSE *asced = ancestrais(a, 6);

    printf("print_TLSE...\n");
    print_TLSE(asced);

    printf("libera_TLSE...\n");
    libera_TLSE(asced);

    printf("libera_TABB...\n");
    libera_TABB(a);
}

void libera_TLSE(TLSE *l){
    TLSE *p = l;
    while(l){
        l = l->prox;
        free(p);
        p = l;
    }
}

void print_TLSE(TLSE *l){
    if (l){
      printf("%d", l->info);
      print_TLSE(l->prox);
    }
    
}

void libera_TABB(TABB *a){
    if (a){
        libera_TABB(a->dir);
        libera_TABB(a->esq);
        free(a);
    }
}

TABB *ins_TABB(TABB *a, int x){
    if (!a){
        TABB *novo = (TABB*)malloc(sizeof(TABB));
        novo->info = x;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }
    if (a->info > x)
        a->esq = ins_TABB(a->esq, x);
    else
        a->dir = ins_TABB(a->dir, x);
    return a;
}

TLSE *ins_ini(TLSE *a, int x){
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo->info = x;
    novo->prox = a;
    return novo;
}

TABB *busca(TABB *a, int x){
    if (!a)
        return NULL;
    if (a->info == x){
        return a;
    }
    if (a->info > x){
        return busca(a->esq, x);
    }
    return busca(a->dir, x);
}

TLSE *ancestrais (TABB *a, int x){
    if (!busca(a, x)){
        return NULL;
    }
    return AA(a, x);
}

TLSE *AA(TABB *a, int x){
    if (a->info == x){
        return ins_ini(NULL, x);
    }
    TABB *p;
    if (a->info > x){
        p = a->esq;
    }
    else{
        p = a->dir;
    }
    return ins_ini (AA(p, x), a->info);
}