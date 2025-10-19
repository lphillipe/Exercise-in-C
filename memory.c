#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = 10; //1. Cria uma variável 'x' na memória e guarda o valor 10 nela.
    int *p = &x; //2. Cria um ponteiro 'p' e o inicializa.

    printf("%i", *p);
}