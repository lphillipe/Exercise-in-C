#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *array_dinamico; // Declara o ponteiro
    array_dinamico = malloc(3 * sizeof(int)); // Aloca memória para 3 inteiros

    if (array_dinamico == NULL) // Verifica se a alocação foi bem-sucedida
    {
        printf("Erro na alocação de memória\n");
        return 1; // Sai do programa com código de erro
    }

    //Indice 0:
    array_dinamico[0] = 42;
    //Indice 1:
    array_dinamico[1] = 100;
    //Indice 2:
    array_dinamico[2] = -5;

    printf("Valores no array dinâmico:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Elemento %d: %d\n", i, array_dinamico[i]);
    }

    free(array_dinamico); // Libera a memória alocada
    printf("Memória liberada com sucesso.\n");
}