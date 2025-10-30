#include <stdio.h>
#include <stdbool.h>

bool is_jpeg_header(unsigned char buffer[])
{
    return buffer[0] == 0xff &&
           buffer[1] == 0xd8 &&
           buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0;
}

int main(void)
{
    unsigned char example1[4] = {0xff, 0xd8, 0xff, 0xe1}; // JPEG valido
    unsigned char example2[4] = {0xff, 0xd8, 0xaa, 0xe1}; // inválido

    if (is_jpeg_header(example1))
    {
        printf("Example 1 é JPEG!\n");
    }
    
    else
    {
        printf("Example 1 não é JPEG.\n");
    }

    if (is_jpeg_header(example2))
    {
        printf("Example 2 é JPEG!\n");
    }

    else 
    {
        printf("Example 2 não é JPEG.\n");
    }

    return 0;
    
}