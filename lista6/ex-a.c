#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"


TPilha *f2p (TFila *f);

int main (void){
    TFila *f = mockFila();
    imprimeFila(f);

    TPilha *p = f2p(f);
    imprimePilha(p);
    
}

TPilha *f2p (TFila *f){
    TPilha *paux1 = inicializaPilha();
    TFila *faux1 = f;
    while(!filaVazia(faux1)){
        push(paux1, retira(faux1));
    }
    TPilha *pret = inicializaPilha();
    while(!pilhaVazia(paux1)){
        push(pret, pop(paux1));
    }
    liberaPilha(paux1);
    return pret;
}