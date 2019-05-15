/*Q2) Implemente uma função em C que receba uma string como parâmetro e retorne uma nova string
com todos os caracteres minúsculos substituídos pelo caracter ‘?’. Por exemplo, se for passada a
string “740-Charitas-Leme”, a função deve retornar a string “740-Ch?r?t?s-L?m?”. A assinatura desta
função deve ser char * codifica (char *str). A string passada como parâmetro não pode ser alterada.
O espaço de memória para a nova string deve ser alocado dinamicamente.
a = 97 e z = 122.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * codifica (char *str);

int main(void){

    char *str = (char *) malloc(sizeof(char) * 31);
    char *resp;

    printf("Informe a string: ");
    scanf(" %30[^\n]", str);

    printf("sentenca: %s\n", str);

    resp = codifica(str);

    printf("resultado: %s\n", resp);

    free(str);
    free(resp);
}

char * codifica(char *str){
    char * resp;
    int i;
    for(i = 0; str[i] != '\0'; i++);

    printf("i: %d\n", i);
    resp = (char *) malloc(sizeof (char) * (i + 1));

    for(i = 0; str[i] != '\0'; i++){
        int c = str[i];
        if (c >= 97 && c<= 122){
            resp[i] = '?';
        }
        else{
            resp[i] = str[i];
        }
    }

    return resp;
}