#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    string texto = get_string("Digite o texto: ");
    int letras = 0;
    int palavras = 1; // começa em 1, porque a última palavra não é seguida de espaço
    int frases = 0;


        for (int i = 0; texto[i] != '\0'; i++)
    {
        char c = texto[i];
        if (isalpha(c))
        {
            letras++;
        }
        else if (c == ' ')
        {
            palavras++;
        }
        else if (c == '.' || c == '!' || c == '?')
        {
            frases++;
        }
    }

    float L = ((float) letras / palavras) * 100;
    float S = ((float) frases / palavras) * 100;

    float indice = 0.0588 * L - 0.296 * S - 15.8;
    int grau = round(indice);

    if (grau < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grau >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grau);
    }

    printf("Letras: %d\n", letras);
    printf("Palavras: %d\n", palavras);
    printf("Frases: %d\n", frases);
}
