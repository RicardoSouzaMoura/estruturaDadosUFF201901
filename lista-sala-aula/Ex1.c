/*
Escreva uma funcao que testa se uma arvore binaria é estritamente balanceada (ou 0 ou 2 filhos)
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct abinaria{
    int info;
    struct abinaria *dir;
    struct abinaria *esq;
}TAB;

int test1(TAB *a);

int main(void){
    TAB *a1 = (TAB*)malloc(sizeof(TAB));
    a1->info = 1;
    a1->dir = NULL;
    a1->esq = NULL;
    TAB *a2 = (TAB*)malloc(sizeof(TAB));
    a2->info = 2;
    a2->dir = NULL;
    a2->esq = NULL;
    TAB *a3 = (TAB*)malloc(sizeof(TAB));
    a3->info = 3;
    a3->dir = NULL;
    a3->esq = NULL;
    TAB *a4 = (TAB*)malloc(sizeof(TAB));
    a4->info = 4;
    a4->dir = NULL;
    a4->esq = NULL;
    TAB *a5 = (TAB*)malloc(sizeof(TAB));
    a5->info = 5;
    a5->dir = NULL;
    a5->esq = NULL;

    a1->esq = a2;
    a1->dir = a3;

    a2->dir = a4;
    a2->esq = a5;

    printf("%d\n", test1(a2));

    free(a5);
    free(a4);
    free(a3);
    free(a2);
    free(a1);
}

int test1(TAB *a){
    if (!a){
        return 0;
    }
    if ((!a->dir) && (!a->esq)){
        return 1;
    }
    if (a->dir && !a->esq){
        return 0;
    }
    if (!a->dir && a->esq){
        return 0;
    }
    int ret = test1(a->dir);
    if (ret){
        return test1(a->esq);
    }
    return 0;
}