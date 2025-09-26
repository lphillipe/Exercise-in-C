#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    int freq[26] = {0};
    string texto = get_string("Digite um texto: ");

    for (int i = 0; texto[i] != '\0'; i++)
    {
        char c = tolower(texto[i]);

        if (c >= 'a' && c <= 'z')
        {
            int pos = c -'a';
            freq[pos]++;
        }
    }
    int primeiro = 1;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
           if (!primeiro)
           {
            printf(", ");
           }
           printf("%c: %d", 'a' + i, freq[i]);
           primeiro = 0;
        }
    }
    printf("\n");
}