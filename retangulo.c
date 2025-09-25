#include <stdio.h>

int main(void) {
    int altura, largura;

    printf("Digite a altura: ");
    scanf("%d", &altura);

    printf("Digite a largura: ");
    scanf("%d", &largura);

    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
