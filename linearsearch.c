#include <stdio.h>
#include <cs50.h>

// prototype function

int linear_search(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int n = get_int("Quantos números você vai digitar? ");
    int arr[n]; // positions n with array

    //read the numbers

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Digite o número %d: ", i + 1);
    }

    int target = get_int("Qual número quer buscar? ");

    int idx = linear_search(arr, n, target);

    if (idx != -1)
    {
        // print indice (0-based) and human position (1-based)
        printf("Encontrando no indice %d (posição %d)\n", idx, idx +1);
    }

    else 
    {
        printf("Não encontrado.\n");
    }

    return 0;
}