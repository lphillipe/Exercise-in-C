#include <stdio.h>
#include <cs50.h>

void selection_sort(int arr[], int n);
void print_array(int arr[], int n);

int main(void)
{
    int n = get_int("Quantos números quer ordenar? ");
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Número %d: ", i + 1);
    }
    printf("\n--- Início da ordenação ---\n");
    selection_sort(arr, n);

    printf("Lista final ordenada: ");
    print_array(arr,n);
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;

            printf("Passo %d: ", i + 1);
            print_array(arr, n);
        }
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
