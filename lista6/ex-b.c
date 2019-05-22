#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"


TFila *inv_fila (TFila *f);

int main (void){
    TFila *f = mockFila();
    imprimeFila(f);

    f = inv_fila(f);
    imprimeFila(f);
    
}

TFila *inv_fila (TFila *f){
    TPilha *paux1 = inicializaPilha();
    TFila *faux1 = f;
    while(!filaVazia(faux1)){
        push(paux1, retira(faux1));
    }
    TFila *fret = inicializaFila();
    while(!pilhaVazia(paux1)){
        fret = insere(fret, pop(paux1));
    }
    liberaPilha(paux1);
    return fret;
}