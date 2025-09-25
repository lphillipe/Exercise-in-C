#include <stdio.h>


int main(void) {



    char continuar = 's';

    while(continuar == 's') {
         int a, b;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);

    char op;
    printf("Escolha a operação (+, -, *, /): ");
    scanf(" %c", &op);

    if(op == '+') {
        printf("Soma: %d\n",a + b);
    } else if(op == '-') {
        printf("Subtração: %d\n", a - b);
    } else if(op == '*') {
        printf("Multiplicação: %d\n", a * b);
    } else if(op =='/' && b != 0) {
        printf("Divisão: %d\n", a / b);
    } else if(op =='/' && b == 0) {
        printf("Não é possivel dividir por 0\n");
    } else {
        printf("Operação inválida tente novamente!\n");
    }
    printf("Deseja fazer outra operação? (s/n): ");
    scanf(" %c", &continuar);

      }
}

