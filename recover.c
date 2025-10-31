#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    FILE *infile = fopen("card.raw", "rb");
    if (infile == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    unsigned char buffer[512];

    FILE *img = NULL;
    int filecount = 0;
    bool found_jpeg = false;

    // Loop: Ler 512 bytes até o fim
    while(1)
    {
        size_t bytes = fread(buffer, 1, 512, infile);

        if (bytes == 0)
        {
            break; // Fim do arquivo
        }
    

        // Verificar se o buffer contém início de JPEG
        bool header = buffer[0] == 0xff &&
                    buffer[1] == 0xd8 &&
                    buffer[2] == 0xff &&
                    (buffer[3] & 0xf0) == 0xe0;

        if (header)
        {
            //  Se já havia JPEG sendo escrito, fechar arquivo anterior
            if (found_jpeg)
            {
                fclose(img);
            }
            
            // criar nome do novo arquivo
            char filename[8];
            sprintf(filename, "%03d.jpg", filecount);
            filecount++;

            // Abrir novo arquivo
            img = fopen(filename, "wb");

            // Marcar que começamos JPEG
            found_jpeg = true;

            // Escrever primeiro bloco

            fwrite(buffer, 1, bytes, img);
        }

        else
        {
            // Se já começamos um JPEG, continuar escrevendo blocos nele
            if (found_jpeg)
            {
                fwrite(buffer, 1, bytes, img);
            }
        }

        if (bytes < 512)
        {
        break;
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    
    fclose(infile);
}