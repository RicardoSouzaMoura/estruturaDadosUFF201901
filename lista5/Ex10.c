/*
Q10) Considerando a seguinte declaração de uma lista encadeada:
typedef struct lista{
    int mat;
    char nome[81];
    float cr;
    struct lista *prox;
}TL;
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1 é a
inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se
as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte: int
Contrario (TL *l1, TL *l2).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int mat;
    char nome[81];
    float cr;
    struct lista *prox;
}TL;

void imprime(TL *l);

int comparaNo(TL *l1, TL *l2);

int Contrario (TL *l1, TL *l2);

int main(void){
    TL *l1 = (TL*)malloc(sizeof(TL));
    l1->mat = 1112;
    strcpy(l1->nome, "Ricardo");
    l1->cr = 7.9;

    TL *l2 = (TL*)malloc(sizeof(TL));
    l2->mat = 1112;
    strcpy(l2->nome, "Ricardo");
    l2->cr = 7.9;

    TL *l3 = (TL*)malloc(sizeof(TL));
    l3->mat = 1112;
    strcpy(l3->nome, "Ricardo");
    l3->cr = 7.9;

    TL *l4 = (TL*)malloc(sizeof(TL));
    l4->mat = 1112;
    strcpy(l4->nome, "Ricardo");
    l4->cr = 7.9;

    l1->prox = l2;
    l2->prox = NULL;
    l3->prox = l4;
    l4->prox = l1;

    printf("######################\n");
    imprime(l1);
    printf("######################\n");
    imprime(l3);
    printf("######################\n");

    //printf("%d\n ", comparaNo(l1, l2));
    //printf("%d\n ", comparaNo(l2, l3));
    //printf("%d\n ", comparaNo(l1, l4));
    //printf("%d\n ", comparaNo(l2, l4));
    //printf("%d\n ", comparaNo(l3, l4));
    //printf("%d\n ", comparaNo(l3, l1));

    printf("%d\n ", Contrario(l1, l3));

    free(l1);
    free(l2);
    free(l3);
    free(l4);
}

int Contrario (TL *l1, TL *l2){
    TL *pilha = NULL;
    TL *aux = l2;
    while(aux){
        TL *itemPilha = (TL*)malloc(sizeof(TL));
        itemPilha->cr = aux->cr;
        itemPilha->mat = aux->mat;
        strcpy(itemPilha->nome, aux->nome);
        itemPilha->prox = pilha;

        pilha = itemPilha;
        aux = aux->prox;
    }

    aux = l1;
    TL *aux2 = pilha;
    
    imprime(aux);
    printf("$$$$$$$$$$$$$$\n");
    imprime(aux2);
    while(aux && aux2){
        //printf("aqui12");
        if (!comparaNo(aux, aux2)){
            return 0;
        }
        aux = aux->prox;
        aux2 = aux2->prox;
    }
//printf("aqui2");
    if ((aux && !aux2) || (!aux && aux2)){
        return 0;
    }
//printf("aqui3");
    return 1;

}

int comparaNo(TL *l1, TL *l2){
    if (!l1 && !l2){
        //printf("aqui1");
        return 1;
    }
    if ((!l1 && l2) || (l1 && !l2)){
        //printf("aqui2");
        return 0;
    }
    if ((l1->mat == l2->mat) && (l1->cr == l2->cr) && strcmp(l1->nome, l2->nome)== 0){
        //printf("aqui3");
        return 1;
    }
    //printf("aqui4");
    return 0;
}

void imprime(TL *l){
    TL *temp = l;
    while(temp){
        printf("%d\n", temp->mat);
        temp = temp->prox;
    }
}