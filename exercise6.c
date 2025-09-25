#include <stdio.h>

int main(void) {
    
    int linhas;
    
    printf("Digite quantas linhas voçê quer no triângulo?");
    scanf("%d", &linhas);

    for (int i = 1; i <= linhas; i ++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}