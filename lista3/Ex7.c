/*
Q7) Escreva um programa que receba duas strings, como parâmetros de entrada, e informe qual é a
maior substring existente nas duas strings. Por exemplo, se as strings de entrada são
ACCTGAACTCCCCCC e ACCTAGGACCCCCC, então a maior substring existente entre as duas
strings será CCCCCC.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *s1, *s2, *s4;

    char *s3 = (char*)malloc(sizeof(char) * 16);

    s1 = (char*)malloc(sizeof(char) * 16);
    s3 = (char*)malloc(sizeof(char) * 16);
    s2 = (char*)malloc(sizeof(char) * 16);
    s4 = (char*)malloc(sizeof(char) * 16);

    scanf(" %16[^\n]", s1);
    scanf(" %16[^\n]", s2);

    int x,i,j,k,l,p=0;
    int maiorTam, maiorTamTemp = 1;

    for(;s1[i] != '\0';i++){
        l = 0;
        maiorTam = 1;
        s3[l] = s1[i];
        for(x = i+1;s1[x] != '\0' && s1[x] == s1[i];x++){
            l++;
            s3[l] = s1[x];
            maiorTam++;
        }
        // imprimindo cadeia a ser testada
        p = 0;
        for(; p < maiorTam; p++){
          printf("%c", s3[p]);
        }
        printf("\n");
        
        // procurar em s2
        int temCadeia = 0;
        for(j = 0;s2[j] != '\0';j++){
            if (s2[j] == s3[0]){
                int quebrouCadeia = 0;
                for(k=j;k < maiorTam; k++){ 
                    if (s2[k] != s3[k-j]){
                        quebrouCadeia = 1;
                        break;
                    }
                }
                if (!quebrouCadeia){
                    temCadeia = 1;
                    break;
                }
            }
        }
        printf("temCadeia/maiorTam/maiorTamTemp: %d/%d/%d\n", temCadeia, maiorTam, maiorTamTemp);
        //copiando um vetor para outro pois S3 vai ser sobrescrito
        if (temCadeia && maiorTam >= maiorTamTemp){
            int index = 0;
            maiorTamTemp = maiorTam;
            for(; index < maiorTam; index++){
                s4[index] = s3[index];
            }
        }
    }

    printf("maior substr: ");
    for(p = 0; p < maiorTamTemp; p++){
        printf("%c", s4[p]);
    }
    printf("\n");

    free(s1);
    free(s2);
    free(s3);
    free(s4);
}