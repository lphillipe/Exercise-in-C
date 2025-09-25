#include <stdio.h>

int main(void) {
    int x;
    printf("Digite o número de x: ");
    scanf("%d", &x);

    int y;
    printf("Digite o número de y: ");
    scanf("%d",&y);

    if (x > y)
        printf("O primeiro número x é maior que o segundo:\n");

    else if (x < y)
        printf("O segundo número y é maior que o primeiro:\n");

    else
        printf("Os dois números são iguais:\n");
}

