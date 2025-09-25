#include <stdio.h>

int main(void) {
    int a, b;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);

    printf("Soma: %d\n", a + b);
    printf("Subtração: %d\n", a - b);
    printf("Multiplicação: %d\n", a * b);

    if (b != 0) {
        printf("Divisão: %d\n", a / b);
    }
    else {
        printf("Não é possivel dividir por zero");
    }
}
