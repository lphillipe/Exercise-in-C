#include <stdio.h>
#include <stdlib.h>

// function intecionally wrong (with leak)
void create_leak(void)
{
    printf("-> Função 'create_leak' calling.\n");
    // allocating 400 bytes (100 *( 4 bytes/int) in HEAP
    int *data = malloc(100 * sizeof(int));

    if (data != NULL) 
    {
        data[0] = 99;
        printf("Memory allocated (address: %p). Usage, but not freed.\n", (void *)data);

    }
    // The pointer 'data' die in leave the function, but the bloco in heap stay 'jail'.
    // That's a memory leak.

}

int main(void)
{
    printf("-- Ex 3: Memory Leak ---\n");
    create_leak();
    printf("-> The program is ending. The block of memory 'data' is leaked!\n");

    return 0;
}