#include <stdio.h>

int main(void) {
    int altura, largura;
    char simbolo;

    printf("Digite a altura: ");
    scanf("%d", &altura);

    printf("Digite a largura: ");
    scanf("%d", &largura);

    printf("Digite o símbolo que deseja usar: ");
    scanf(" %c", &simbolo);

    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            if(i == 0 || i == altura - 1 || j == 0 || j == largura - 1) {
                printf("%c", simbolo);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
