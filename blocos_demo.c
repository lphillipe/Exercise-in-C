#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 1. Abre o arquivo "sd_simulado.raw"
    FILE *file = fopen("sd_simulado.raw", "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    // 2. Cria um buffer de 512 bytes
    unsigned char buffer[512];

    int bloco = 0; // Contador de blocos.

    // 3 . Lê até o final do arquivo, 512 bytes por vez
    while (1)
    {
        size_t bytes = fread(buffer, 1, 512, file);

        if (bytes == 0)
        {
            printf("Fim do arquivo alcançado.\n");
            break;
        }
        printf("\n--- Bloco %d ---\n", bloco);
        printf("Bytes lidos: %zu\n", bytes);

        // Mostra os 8 primeiros bytes em hexadecimal
        printf("Bytes iniciais (hex): ");
        for (int i = 0; i < 8 && i< bytes; i++)
        {
            printf("%02x ", buffer[i]);
        }
        printf("\n");

        // Mostra a posição atual do cursor no arquivo
        long pos = ftell(file);
        printf("Posição atual do cursor: %ld\n", pos);

        bloco++;

        // Se a leitura for menor que 512 bytes, terminou o arquivo

        if (bytes < 512)
        {
            printf("Bloco final incompleto - fim do arquivo.\n");
            break;
        }
    }

    fclose(file);
    return 0;
}