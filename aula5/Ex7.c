/*
Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void* i_p ( TLSE *l).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

void i_p ( TLSE *l);
void imprime(TLSE *l);

int main(void){

    TLSE* test11 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test12 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test13 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test14 = (TLSE*)malloc(sizeof(TLSE));
    TLSE* test15 = (TLSE*)malloc(sizeof(TLSE));
    test11->info = 4;
    test12->info = 0;
    test13->info = 8;
    test14->info = 6;
    test15->info = 1;

    test11->prox = test12;
    test12->prox = test13;
    test13->prox = test14;
    test14->prox = test15;
    test15->prox = NULL;

    printf("\n lista inteira...\n");
    imprime(test11);

    i_p(test11);

    printf("\n ocorrencias ordenadas 2...\n");
    imprime(test11);
    printf("\n");

    
    free(test11);
    free(test12);
    free(test13);
    free(test14);
    free(test15);

    printf("\n");
    

}

void i_p ( TLSE *l){
    if (!l || !l->prox){
        return;
    }
    TLSE *par = l;
    while(par){
        while(par && par->info % 2 != 0){
            par = par->prox;
        }
        if (!par){
            return;
        }
        TLSE *impar = par;
        while(impar && impar->info % 2 == 0){
            impar = impar->prox;
        }
        if (!impar){
            return;
        }

        int info_v = par->info;
        TLSE *aux = par;
        while(aux != impar){
            aux = aux->prox;
            int info_t = aux->info;
            aux->info = info_v;
            info_v = info_t;
        }
        par->info = info_v;
    } 
}

void imprime(TLSE *l){
    TLSE *temp = l;
    while(temp){
        printf("%d\n", temp->info);
        temp = temp->prox;
    }
}