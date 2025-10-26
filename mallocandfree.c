#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int tamanho = 5;

    // 1. The point receive the address of memory allocated

    int *bloco = NULL; // its good initialize pointers as NULL

    printf("--- Ex 3: Corretion of Memopry leak ---\n");

    // 2. The KEY: Asking 5 spaces * sizeof (int) bytes.
    bloco = malloc(tamanho * sizeof(int));

    // Checking the security
    if (bloco == NULL)
    {
        printf("Failed to allocate. The program cannot continue.");
        return 1;
    }

    // --- Use of memory ---
    printf("Memory allocated with sucess. Incial address: %p\n", (void*)bloco);

    for (int i = 0; i < tamanho; i++)
    {
        bloco[i] = i * 10;
        printf("Block %d] (valor: %d) | Address: %p\n", i, bloco[i], (void*)&bloco[i]);
    }

    // 4. THE CRUCIAL END: Returning the memory block to the system.
    // In this way, the program avoid memory leaks.
    free(bloco);

    printf("\nMemory freed. The program is ending. (ALL CLEAN)\n");
}