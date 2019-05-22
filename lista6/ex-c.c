#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"


TFila *sep_fila(TFila *f);

int main (void){
    TFila *f = mockFila();
    imprimeFila(f);

    TFila *f2 = sep_fila(f);
    imprimeFila(f);
    imprimeFila(f2);
    
}

TFila *sep_fila(TFila *f){
    TFila *fpar = inicializaFila();
    TFila *fimpar = inicializaFila();
    TFila *faux = f;
    while(!filaVazia(faux)){
        int item = retira(faux);
        if (item % 2 ==0){
            fpar = insere(fpar, item);
        }
        else{
            fimpar = insere(fimpar, item);
        }
    }
    faux = fimpar;
    while(!filaVazia(faux)){
        f = insere(f, retira(faux));
    }
    liberaFila(fimpar);
    liberaFila(faux);
    return fpar;
}