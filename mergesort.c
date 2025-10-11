#include <stdio.h>
#include <cs50.h>

// Prototypes functions
void merge_sort(int arr[], int inicio, int fim);
void merge(int arr[], int inicio, int meio, int fim);
void print_array(int arr[], int n);


int main(void)
{
    int arr[] = {8,3,5,2,9,1};
    int n = 6;

    printf("Antes: ");
    print_array(arr, n);

    merge_sort(arr, 0, n- 1);

    printf("Depois: ");
    print_array(arr, n);

}

void merge_sort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(arr, inicio, meio);
        merge_sort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim);
    }
}
void merge(int arr[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    // copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[inicio + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    // join and compare the elements
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
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

