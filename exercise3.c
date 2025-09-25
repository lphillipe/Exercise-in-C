#include <stdio.h>

int main(void) {
    int nota;
    printf("Digite sua nota: ");
    scanf("%d", &nota);

    if (nota >= 60)
        printf("Aluno aprovado!");
    else if (nota >= 40)
        printf("Aluno em recuperação!");
    else 
        printf("Aluno está reprovado!");
}
