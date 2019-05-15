/*
Q8) Considerando as seguintes declarações de uma lista encadeada:
typedef struct lista{
    int mat;
    char nome[81];
    float cr;
    struct lista *prox;
}TLista;
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1 e l2
são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se as
listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: int igual
(TLista *l1, TLista *l2).
OBS: protótipo de função que pode ser útil: int strcmp (char *s, char *t).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int mat;
    char nome[81];
    float cr;
    struct lista *prox;
}TLista;
int igual (TLista *l1, TLista *l2);
int comparaNo (TLista *l1, TLista *l2);

int main(void){
    TLista *l1 = (TLista*)malloc(sizeof(TLista));
    l1->mat = 2;
    strcpy(l1->nome, "Ricardo");
    l1->cr = 7.9;

    TLista *l2 = (TLista*)malloc(sizeof(TLista));
    l2->mat = 2;
    strcpy(l2->nome, "Ricardo");
    l2->cr = 7.9;

    TLista *l3 = (TLista*)malloc(sizeof(TLista));
    l2->mat = 2;
    strcpy(l2->nome, "Ricardo");
    l2->cr = 7.9;

    l2->prox = l3;
    l1->prox = l3;

    printf("%d\n ", igual(l1, l2));

    free(l1);
    free(l2);
    free(l3);
}

int igual (TLista *l1, TLista *l2){
    //printf("iniciando comparacao...\n");
    if (!l1 && !l2){
        //printf("l1 e l2 vazios\n");
        return 1;
    }
    if ((l1 && !l2) || (!l1 && l2)){
        //printf("l1 ou l2 vazios\n");
        return 0;
    }
    if (comparaNo(l1, l2)){
        //printf("l1 ou l2 iguais\n");
        return 1 && igual(l1->prox, l2->prox);
    }
    return 0;
}

int comparaNo (TLista *l1, TLista *l2){
    if (l1 && l2){
        if ((l1->mat == l2->mat) 
            && (l1->cr == l2->cr) 
            && (strcmp(l1->nome, l2->nome)==0)){
            return 1;
        }
    }
    return 0;
}