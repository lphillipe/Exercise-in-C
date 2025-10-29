#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 1. Abre um arquivo de exemplo em modo leitura binária
    FILE *file = fopen("exemplo.bin", "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // 2, Cria um buffer de 8 bytes
    unsigned char buffer[8];

    // 3. Mostra a posição atual do cursor
    long pos = ftell(file);
    printf("Posição inicial do cursor: %ld\n", pos);

    // 4. Lê 8 bytes e mostra quanto foram realmente lidos
    size_t bytes = fread(buffer, 1, 8, file);
    printf("Bytes lidos: %zu\n", bytes);

    // 5. Mostra os valores lidos (em hexadecimal)
    printf("Conteúdo lido (em hex): ");
    for (int i = 0; i < bytes; i++)
    {
        printf("%02x ", buffer[i]);
    }
    printf("\n");

    // 6. Mostra a posição atual do cursor após a leitura
    pos = ftell(file);
    printf("Posição do cursor após leitura: %ld\n", pos);

    // 7. LÊ mais 8 bytes para ver o cursor avançar novamente
    fread(buffer, 1, 8, file);
    pos = ftell(file);
    printf("Posição do cursor após segunda leitura: %ld\n", pos);

    fread(buffer, 1, 8, file);
    pos = ftell(file);
    printf("Posição do cursor após terceira  leitura: %ld\n", pos);
    
    fclose(file);
}