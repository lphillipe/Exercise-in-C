#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// function auxiliary: convert a string to lowercase

void to_lowercase(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
    }
}

int main(void)
{
    int n = get_int("Quantas palavras você quer digitar? ");
    if (n<=0)
    {
        printf("Número inválido\n");
        return 1;
    }

    string arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_string("Digite a %dª palavra: ", i + 1);
        to_lowercase(arr[i]);
    }

    string target = get_string("Digite a palavra que você quer buscar: ");
    to_lowercase(target);

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
        printf("A palavra '%s' foi encontrada %d vezes.\n", target, contador);
    }
    else
    {
        printf("A palavra '%s' não foi encontrada.\n", target);
    }
}