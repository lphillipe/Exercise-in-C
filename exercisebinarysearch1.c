#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int n = get_int("Quantas palavras você quer digitar? ");
    if (n <= 0)
    {
        printf("Número inválido.\n");
        return 1;
    }

    string arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_string("Digite a palavra %d: ", i + 1);
    }

    string target = get_string("Qual palavra você quer buscar? ");

    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], target) == 0)
        {
            contador++;
        }
    }

    if (contador > 0)
    {
        printf("A palavra \"%s\" aparece %d vezes.\n", target, contador);
    }
    else
    {
        printf("A palavras \"%s\" não foi encontrada.\n", target);
    }
}