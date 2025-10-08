#include <stdio.h>
#include <cs50.h>

// prototype function

int binary_search_recursive(int arr[], int target, int inicio, int fim)
{
    if (inicio > fim)
    {
        return -1;
    }

    int meio = inicio + (fim - inicio) /2;

    if (arr[meio] == target)
    {
        return meio; // found
    }
    else if (target < arr[meio])
    {
        return binary_search_recursive(arr, target, inicio, meio -1);
    }
    else
    {
        return binary_search_recursive(arr, target, meio + 1, fim);
    }
}

int main(void)
{
    int n = get_int("Quantos números em ordem crescente? ");
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Digite o número %d: ", i + 1);
    }

    int target = get_int("Qual número quer buscar? ");
    int idx = binary_search_recursive(arr, target, 0, n - 1);

    if (idx != -1)
    {
        printf("Encontrando no indice %d (posição %d)\n", idx, idx + 1);
    }
    else
    {
        printf("Não encontrado\n");
    }
    return 0;
}