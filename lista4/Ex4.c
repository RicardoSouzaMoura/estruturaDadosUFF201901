/*
Q4) A matriz de Hadamard H(N), usada em projetos de programas corretores de erros, é uma
matriz N por N, onde N é potência de dois, de elementos booleanos (isto é, elementos 0 e 1) que
satisfaz a seguinte propriedade: dadas duas linhas distintas i e j, onde 0 <= i < N e 0 <= j < N,
desta matriz, a quantidade de elementos distintos nestas linhas é sempre igual a N/2. Abaixo
exemplica-se H(1), H(2) e H(4).

H(1) | H(2) | H(4)
-----------+--------+------------
1   |   1 1     | 1 1 1 1 | 1 1 1 1  1 1 1 1
    |   1 0     | 1 0 1 0 | 1 0 1 0  1 0 1 0
                | 1 1 0 0 | 1 1 0 0  1 1 0 0
                | 1 0 0 1 | 1 0 0 0  1 0 0 0 
                            
                            1 1 1 1  0 0 0 0
                            1 0 1 0  0 1 0 1
                            1 1 0 0  0 0 1 1
                            1 0 0 0  0 1 1 1

Para construir H(M), onde M = 2 * N, divide-se a matriz H(M) em quatro partes iguais, chamadas
de quadrantes, repete-se três vezes a matriz H(N) nos quadrantes de menores índices, e no
quadrante de maiores índices de H(M), inverte-se a matriz H(N). Implemente um programa que
imprima a matriz H(N) na console. A dimensão desta matriz deve ser lida pelo seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

int ** desenhaH(int n);

int main(void){
    int dim;
    printf("Informe a dimensão: ");
    scanf("%d", &dim);

    int dimCheck = dim;
    while (dimCheck > 1){
        if (dimCheck % 2 != 0){
          printf("Dimensão tem que ser potência de 2\n");
          exit(-1);
        }
        dimCheck = dimCheck / 2;
    }

    int **H = (int **)malloc(sizeof(int *) * dim);

    int i=0;
    for(;i < dim; i++){
        int *l = (int*)malloc(sizeof(int) * dim);
        H[i] = l;
        //int *l = H[i];
        // l = (int*)malloc(sizeof(int) * dim);
    }
// populando matriz

    H = desenhaH(dim);

    printf("imprimindo H...\n");
    int j=0;
    for(i=0;i < dim; i++){
        for(j=0;j < dim; j++){
            printf("%d", H[i][j]);
            if (j == (dim/2)-1){
                printf(" ");
            }
        }
        if (i == (dim/2)-1){
                printf("\n");
        }
        printf("\n");
    }
    printf("\n");

// desalocando
    for(i=0;i < dim; i++){
        free(H[i]);
    }

    free(H);

}

/*
H(1) | H(2) | H(4)
-----------+--------+------------
1   |   1 1     | 1 1 1 1 | 1 1 1 1  1 1 1 1
    |   1 0     | 1 0 1 0 | 1 0 1 0  1 0 1 0
                | 1 1 0 0 | 1 1 0 0  1 1 0 0
                | 1 0 0 1 | 1 0 0 0  1 0 0 0 
                            
                            1 1 1 1  0 0 0 0
                            1 0 1 0  0 1 0 1
                            1 1 0 0  0 0 1 1
                            1 0 0 0  0 1 1 1
*/
int ** desenhaH(int n){
    
    int i=0;
    int j=0;
    if (n == 1){
        int **resp = (int**)malloc(sizeof(int*) * 1);
        int *l = (int*)malloc(sizeof(int) * 1);
        l[0] = 1;
        resp[0] = l;
        return resp;
    }
    printf("pedindo formacao de n: %d\n", n/2);
    int **respTemp = desenhaH(n/2);
    printf("reconstruindo com n: %d\n", n);
    int **resp = (int**)malloc(sizeof(int*) * n);
    // ajustar realocacao
    printf("realocando H...\n");
    for(i=0;i < n; i++){
        resp[i] = (int*)malloc(sizeof(int) * n);
    }
    
    printf("preenchendo H...\n");
    for(i=0;i < n/2; i++){
        for(j=0;j < n/2; j++){
            resp[i][j] = respTemp[i][j];
            resp[i][j+(n/2)] = respTemp[i][j];
            resp[i+(n/2)][j] = respTemp[i][j];
            resp[i+(n/2)][j+(n/2)] = !respTemp[i][j];
        }
    }

    return resp;
}