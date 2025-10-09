#include <stdio.h>
#include <cs50.h>

void insertion_sort(int arr[], int n);
void print_array(int arr[], int n);

int main(void)
{
    int n = get_int("Quantos números você quer ordenar? ");
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Número %d: ", i + 1 );
    }

    insertion_sort(arr, n);

    printf("Lista ordenada:\n");
    print_array(arr, n);
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = chave;
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i <n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}