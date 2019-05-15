/*
 Q2) Considere duas matrizes de inteiros de dimensões m1xn1 e m2xn2, onde m1 e n1
representam, respectivamente, o número de linhas e o número de colunas da primeira matriz, e
m2 e n2 representam, respectivamente, o número de linhas e o número de colunas da segunda
matriz. Escreva uma função que realize a multiplicação destas duas matrizes sem alterar nem a
primeira e nem a segunda matriz: int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2)
*/

#include <stdio.h>
#include <stdlib.h>

int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2);

int main(void){

    // 10x5 5x10 = 10x10
    int m1 = 10;
    int m2 = 5;
    int n1 = 5;
    int n2 = 10;

    printf("m1: %d\n", m1);
    printf("M2: %d\n", m2);
    printf("n1: %d\n", n1);
    printf("n2: %d\n", n2);

    int **mat1 = (int **)malloc(sizeof(int*) * m1);
    int **mat2 = (int **)malloc(sizeof(int*) * m2);
    int **mat3 = (int **)malloc(sizeof(int*) * m1);

    int i,j=0;
    for(;i < m1; i++){
        int *cols = (int*) malloc(sizeof(int) * n1);
        for(j=0; j < n1; j++){
            cols[j] = 3;
        }
        mat1[i] = cols;
    }

    for(i=0;i < m2; i++){
        int *cols = (int*) malloc(sizeof(int) * n2);
        for(j=0; j < n2; j++){
            cols[j] = 2;
        }
        mat2[i] = cols;
    }

    for(i=0;i < m1; i++){
        int *cols = (int*) malloc(sizeof(int) * n2);
        mat3[i] = cols;
    }

    // print mat1
    for(i = 0; i < m1; i++){
        for(j=0; j < n1; j++){
            printf("%d,", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    
    // print mat2
    //printf("$$$$$$$$$$$$$$$$M2: %d", m2);
    for(i = 0; i < m2; i++){
        for(j=0; j < n2; j++){
            printf("%d,", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    
    // print mat1 * mat2
    mat3 = mult(m1, n1, mat1, m2, n2, mat2);
    for(i = 0; i < m1; i++){
        for(j=0; j < n2; j++){
            printf("%d,", mat3[i][j]);
        }
        printf("\n");
    }
    
    //free
    for(i=0;i < n1; i++){
        free(mat1[i]);
    }

    for(i=0;i < n2; i++){
        free(mat2[i]);
    }

    for(i=0;i < n2; i++){
        free(mat3[i]);
    }

    free(mat1);
    free(mat2);
    free(mat3);

    
}

int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2){
    printf("m1xn1: %dx%d, m2xn2: %dx%d\n", m1, n1, m2, n2);
    
    if (n1 != m2){
        return NULL;
    }
    int **lines = (int **)malloc(sizeof(int*) * m1);
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int x=0;
    int y=0;
    for(;i < m1; i++){
        int *cols = (int*)malloc(sizeof(int) * n2);
        lines[i] = cols;
    }

    int valor = 0;
    for(l=0; l < m1; l++){
        for(x=0; x < n2; x++){
            valor = 0;
            for(k=0; k < n1; k++){
                //printf("k: %d", k);
                int m1n1 = mat1[l][k];
                int m2n2 = mat2[k][x];
                valor += m1n1 * m2n2;
                //printf("m1n1xm2n2=valor/%dx%d=%d", m1n1, m2n2, valor);
            }
            //printf("%d,%d: %d", l,x,valor);
            lines[l][x] = valor;
        }
    }
    

    return lines;

}
