#include <stdio.h>
#include <cs50.h>

int main(void) {
    string nome = get_string("Digite o seu nome: ");
    printf("Olá, %d\n", nome);
}