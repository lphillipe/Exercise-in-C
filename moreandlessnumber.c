#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Quantos números você quer digitar? ");
    int primeiro = get_int("Digite o primeiro número: ");
    int maior = primeiro;
    int menor = primeiro;

    for (int i = 1; i < n; i++)
    {
        int num = get_int("Digite um número: ");

        if (num > maior)
        {
            maior = num;
        }
        if (num < menor)
        {
            menor = num;
        }
    }
    printf("Maior número: %d\n", maior);
    printf("Menor número: %d\n", menor);

}