#include <stdio.h>
#include <cs50.h>

// prototype function

int binary_search(int arr[], int n, int target)
{
    int inicio = 0;
    int fim = n -1;

    while (inicio <= fim)
    {
        // safe midle calculation (avoid overflow)
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == target)
        {
            return meio; //found
        }
        else if (arr[meio] < target)
        {
            inicio = meio + 1; //search on the left
        }
        else{
            fim = meio - 1; //search on the left
        }
    }
    return -1; //not found
    
}

int main(void)
{
    int n = get_int("Quantos números(em ordem crescente)? ");
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Digite o número %d:", i + 1);
    }

    int target =get_int("Qual número quer buscar?");
    int idx = binary_search(arr, n, target);

    if (idx != -1)
    {
        printf("Encontrando no índice %d(posição %d)\n", idx, idx + 1);
    }
    else
    {
        printf("Não encontrado.\n");
    }
    return 0;
}