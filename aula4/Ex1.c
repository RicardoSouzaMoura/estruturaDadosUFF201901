/*
Q1) Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva
um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma
solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9
somente uma vez).

5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
-------+-------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
-------+-------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9
*/

#include <string.h>
#include <stdio.h>

int main(void){
    int mat[9][9] = {5, 3, 4, 6, 7, 8, 9, 1, 2, 
                     6, 7, 2, 1, 9, 5, 3, 4, 8, 
                     1, 9, 8, 3, 4, 2, 5, 6, 7,
                     8, 5, 9, 7, 6, 1, 4, 2, 3,
                     4, 2, 6, 8, 5, 3, 7, 9, 1,
                     7, 1, 3, 9, 2, 4, 8, 5, 6,
                     9, 6, 1, 5, 3, 7, 2, 8, 4,
                     2, 8, 7, 4, 1, 9, 6, 3, 5,
                     3, 4, 5, 2, 8, 6, 1, 7, 9};
    
    int i,j,k = 0;
    int sudoku = 1;
    for (i=0; i < 9 && sudoku; i++){
        for(j=0; j < 9 && sudoku; j++){
            int item = mat[i][j];
            //printf("%d-", item);
            for(k=j+1;k < 9 && sudoku; k++){
                //printf("%d,", mat[i][k]);
                if (item == mat[i][k]){
                    sudoku = 0;
                }
            }
            //printf("\n");
            for(k=i+1;k < 9 && sudoku; k++){
                //printf("%d,", mat[k][j]);
                if (item == mat[k][j]){
                    sudoku = 0;
                }
            }
            //printf("\n\n");
        }
    }

    for(i=0; i < 9 && sudoku; i = i+3){
        for(j=0; j < 9; j = j+3){
            int item = mat[i][j];
            //printf("%d-", item);
            for(k=j+1; k < j+3; k++){
                //printf("%d,", mat[i][k]);
                if (item == mat[i][k]){
                    sudoku = 0;
                }
            }
            //printf("\n");
            for(k=j; k < j+3; k++){
                //printf("%d,", mat[i+1][k]);
                if (item == mat[i+1][k]){
                    sudoku = 0;
                }
                //printf("%d,", mat[i+2][k]);
                if (item == mat[i+2][k]){
                    sudoku = 0;
                }
            }
            //printf("\n\n");
        }
    }

    printf("sudoku: %d\n", sudoku);
}