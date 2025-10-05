#include <stdio.h>
#include <cs50.h>
#include <string.h>

int linear_search(string arr[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], target) == 0)
        {
            return i;
        }
    }
    return -1;

}

int main(void)
{
    int n = get_int("Quantas palavras você vai digitar? ");
    string arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_string("Digite a palavra %d: ", i + 1);
    }
    string target = get_string("Qual palavra quer buscar? ");
    
    int idx = linear_search(arr, n, target);

    if (idx != -1)
    {
        printf("Encontrada no índice %d (posição %d)\n", idx, idx + 1);
    }
    
    else
    {
        printf("Não encontrada\n");
    }
}