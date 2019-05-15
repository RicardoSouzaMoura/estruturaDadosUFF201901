/*
Q6) Supondo as seguintes declarações:
int x, y, z;
int teste;
x = 5;
y = x++;
z = x--;
Informe os valores de teste, x, y e z depois da avaliação das seguintes expressões:
(a) teste = !y == !x;
(b) teste = ((x++ > y) || (--z <= y));
(c) teste = ((!x) || (!(!z)));
(d) teste = (((x + y) > z) && (x++));
(e) teste = x && y + !3 || 4;
*/
#include <stdio.h>

int main(){

    int x, y, z;
    int teste;
    x=5;
    y=x++; // y=5, x=6
    z=x--; // z=6, x=5

    teste = !y == !x; // 1
    printf("%d", teste);

    x=5;
    y=x++; // y=5, x=6
    z=x--; // z=6, x=5

    teste = ((x++ > y) || (--z <= y)); // 6 > 5 || 5 <= 5 , 1
    printf("\n%d", teste);

    x=5;
    y=x++; // y=5, x=6
    z=x--; // z=6, x=5

    teste = ((!x) || (!(!z))); // falso || verdadeiro, 1 
    printf("\n%d", teste);

    x=5;
    y=x++; // y=5, x=6
    z=x--; // z=6, x=5

    teste = (((x + y) > z) && (x++)); // 10 > 6 && 6, 1
    printf("\n%d", teste);

    x=5;
    y=x++; // y=5, x=6
    z=x--; // z=6, x=5

    teste = x && y + !3 || 4; // x && y + falso || 4, x && 5 || 4, 1 || 4, 1
    printf("\n%d\n", teste);
}