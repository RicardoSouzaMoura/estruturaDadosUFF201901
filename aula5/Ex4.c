/*
Q4) Considere a existência de um tipo que representa um aluno numa universidade
hipotética:

typedef struct aluno {
int mat;
float cr;
struct aluno *prox;
}TAluno;

Escreva uma função que copie uma lista. A lista original deve permanecer inalterada. O
protótipo da função é o seguinte: TAluno *copia (TAluno *l).
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct aluno {
    int mat;
    float cr;
    struct aluno *prox;
}TAluno;

TAluno *copia (TAluno *l);

int main(void){
    TAluno* test11 = (TAluno*)malloc(sizeof(TAluno));
    TAluno* test12 = (TAluno*)malloc(sizeof(TAluno));
    TAluno* test13 = (TAluno*)malloc(sizeof(TAluno));
    TAluno* test14 = (TAluno*)malloc(sizeof(TAluno));
    TAluno* test15 = (TAluno*)malloc(sizeof(TAluno));
    test11->mat = 1;
    test11->cr = 1.0;
    test12->mat = 2;
    test12->cr = 2.0;
    test13->mat = 3;
    test13->cr = 3.0;
    test14->mat = 4;
    test14->cr = 4.0;
    test15->mat = 5;
    test15->cr = 5.0;

    test11->prox = test12;
    test12->prox = test13;
    test13->prox = test14;
    test14->prox = test15;
    test15->prox = NULL;

    TAluno *p = test11;
    printf("\n Original...\n");
    while(p){
        printf("%d, %f\n", p->mat, p->cr);
        p = p->prox;
    }

    printf("\n Copiando...\n");
    TAluno *novo = copia(test11);

    printf("\n Copia...\n");
    p = novo;
    while(p){
        printf("%d-%f\n", p->mat, p->cr);
        p = p->prox;
    }
    printf("\n");
}

TAluno *copia (TAluno *l){
    TAluno *novo;
    TAluno *fim;
    TAluno *p = l;
    while(p){
       TAluno *novoTemp = (TAluno*)malloc(sizeof(TAluno));
       novoTemp->cr = p->cr;
       novoTemp->mat = p->mat;
       novoTemp->prox = NULL;
       if (!novo){
           novo = novoTemp;
           fim = novo;
       }else{
           fim->prox = novoTemp;
           fim = novoTemp;
       }
       p = p->prox;
    }

    return novo;
}