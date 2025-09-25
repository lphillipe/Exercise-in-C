#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int ("Quantos números você quer digitar: ");
    int numeros[n];
    int soma = 0;
    float media;

    for(int i = 0; i < n; i ++)
    {
        numeros[i] = get_int("Digite um número: ");
        soma += numeros[i];
    }
    media = (float)soma / n;
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", media);
}
