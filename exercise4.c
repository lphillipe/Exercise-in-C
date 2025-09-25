#include <stdio.h>


int main(void) {
    int n;
    printf("Digite um número: ");
    scanf("%d",&n);

    for(int i = 1; i <= n; i++) {
        printf("%d", i);
    }
}
