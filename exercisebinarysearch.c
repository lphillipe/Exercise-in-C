#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Quantos números você vai digitar? ");
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Digite o numero %d: ", i + 1);
    }

    int target = get_int("Qual o número você quer buscar? ");

    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            contador ++;
        }
    }
    if (contador > 0)
    {
        printf("O número %d aparece % d vezes no vetor.\n", target, contador);
    }
    else
    {
        printf("O número %d não foi encontrado.\n", target);
    }
}