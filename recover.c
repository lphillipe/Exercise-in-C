#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("card.raw", "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    unsigned char buffer[512];
    size_t bytes = fread(buffer, 1, 512, file);

    printf("Bytes lidos: %zu\n", bytes);

    

    int count = 0;

    while (fread(buffer, 1, 512, file) == 512)
    {
        count++;
    }

    printf("Blocos lidos: %d\n", count);

    fclose(file);
}