#include <stdio.h>

int main(void) {
    char nome[50];
    printf("Digite o seu nome: ");
    scanf("%s", nome);

    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Olá %s, você tem, %d anos", nome, idade);
}
