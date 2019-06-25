/*
Dada uma AB e uma informacao, retorneo sucessor na arvore. 
Se x é o maior elemento retorne ele mesmo */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct a_bin{
    int info;
    struct a_bin *esq;
    struct a_bin *dir;
} TAB;

TAB *ins_AB(TAB *a, int x, int pai);
void libera_TAB(TAB *a);

int sucessor(TAB *a, int x);
int sucessor_x(TAB *a, int x, int maior_x);
TAB *busca(TAB *a, int x);

TAB *busca(TAB *a, int x){
    if (!a || a->info == x){
        return a;
    }
    TAB *p = busca(a->dir, x);
    if (!p)  return busca(a->esq, x);
}

int main(void){
    TAB *a = ins_AB(NULL, 10, 0);
    a = ins_AB(a, 5, 0);
    a = ins_AB(a, 12, 10);
    a = ins_AB(a, 67, 5);
    a = ins_AB(a, 3, 67);
    a = ins_AB(a, 6, 12);

    printf("%d\n", sucessor(a, 10));

    libera_TAB(a);
}

void libera_TAB(TAB *a){
    if (a){
        libera_TAB(a->dir);
        libera_TAB(a->esq);
        free(a);
    }
}

TAB *ins_AB(TAB *a, int x, int pai){
    if (!a){
        if  (pai != 0) return NULL;
        TAB *novo = (TAB*)malloc(sizeof(TAB));
        novo->info = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (pai == 0){
        TAB *novo = (TAB*)malloc(sizeof(TAB));
        novo->info = x;
        novo->esq = NULL;
        novo->dir = NULL;
        TAB *p = a;
        while(p->dir){
            p = a->dir;
        }
        p->dir = novo;
        return a;
    }
    if (a->info == pai){
        TAB *f = a->esq;
        TAB *novo = (TAB*)malloc(sizeof(TAB));
        novo->info = x;
        novo->esq = NULL;
        novo->dir = NULL;
        if (f){
            while(f->dir){
                f = f->dir;
            }
        }
        if (f)
            f->dir = novo;
        else{
            a->esq = novo;
        }
        return a;
    }
    a->dir = ins_AB(a->dir, x, pai);
    a->esq = ins_AB(a->esq, x, pai);
    return a;
}

int sucessor(TAB *a, int x){
    int maior_x = __INT_MAX__;
    if (!busca(a, x)) return -1;
    maior_x = sucessor_x(a, x, maior_x);
    if(maior_x == __INT_MAX__){
        maior_x = x;
    }
    return maior_x;
}

int sucessor_x(TAB *a, int x, int maior_x){
    if (!a){
        return maior_x;
    }
    if (a->info > x && a->info < maior_x){
        maior_x = a->info;
    }
    maior_x = sucessor_x(a->esq, x, maior_x);
    maior_x = sucessor_x(a->dir, x, maior_x);
    return maior_x;
}
