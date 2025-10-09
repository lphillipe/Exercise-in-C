#include <stdio.h>
#include <cs50.h>

// function for ordering an array using bubble sort

void bubble_sort(int arr[], int n);

int main(void)
{
    int n = get_int ("Quantos números quer ordenar? ");
    int arr[n];

    // read user numbers

    for (int i = 0;i < n; i++)
    {
        arr[i] = get_int("Digite o número %d: ", i + 1);
    }

    bubble_sort(arr, n);

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function that implements bubble sort
void bubble_sort(int arr[], int n)
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
        }
    }
}