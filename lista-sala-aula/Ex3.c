/* Dada uma ABB, teste se cada um dos nós, exceto a raiz e as folhas, tenha somente 1 filho
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct a_bin{
    int info;
    struct a_bin *esq;
    struct a_bin *dir;
} TAB;

TAB *ins_AB(TAB *a, int x, int pai);
int teste3(TAB *a);
int teste4(TAB *a);
void libera_TAB(TAB *a);

int main(void){
    TAB *a = ins_AB(NULL, 10, 0);
    a = ins_AB(a, 5, 0);
    a = ins_AB(a, 12, 10);
    a = ins_AB(a, 67, 5);
    a = ins_AB(a, 3, 67);
    a = ins_AB(a, 6, 12);

    printf("%d\n", teste3(a));

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

int teste3(TAB *a){
    if (!a){
        return teste4(a->esq) && teste4(a->dir);
    }
    return 1;
}

int teste4(TAB *a){
    if (!a)
        return 1;
    int ret = teste3(a->dir);
    if (ret == 1){      
        ret = teste3(a->esq);
        if (ret == 1){
            if (!a->dir && !a->esq)
                return 1;
            if (!a->dir && a->esq)
                return 1;
            if (a->dir && !a->esq)
                return 1;
            if (a->dir && a->esq)
                return 0;
        }
    }
    return 0;
}