/*
Q1) Implemente uma função em C que receba uma string como parâmetro e substitua todas as suas
letras por predecessoras do alfabeto, trocando maiúsculas por minúsculas. Por exemplo, a string
“Amor” seria alterada para “zLNQ”. Esta função deve obedecer o seguinte protótipo: void
shift_troca_string (char *str). A letra ‘a’ deve ser substituída por ‘Z’ (e ‘A’ por ‘z’). Caracteres que não
forem letras devem ser substituídos por ‘!’. Sabe-se que A = 65, Z = 90, a = 97 e z = 122.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void shift_troca_string (char *str);

int main(void){

    char *str;
    str = (char *) malloc (sizeof(char)*15);

    printf("Informe a string: \n");
    scanf(" %30[^\n]", str);

    printf("%s\n", str);

    shift_troca_string(str);

    printf("%s\n", str);

}

void shift_troca_string (char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        int c = str[i];

        if ((c > 65 && c <= 90) || (c > 97 && c <= 122)){
            str[i] = c > 90 ? c - 32 - 1 : c + 32 - 1;
        }
        else{
            if (c == 65){
                str[i] = 122;
            }
            else if (c == 97){
                str[i] = 90;
            }
            else
              str[i] = '!';
        }
        //printf("%d\n", c);
    }
}