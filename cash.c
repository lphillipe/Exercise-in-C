#include <stdio.h>

int main(void) {
    int valor;
    printf("Qual valor você precisa dar de troco?");
    scanf("%d", &valor);
    
    int restante = valor;
    
    int moedas25 = restante /25;
    restante = restante % 25;

    int moedas10 = restante /10;
    restante = restante % 10;
    
    int moedas5 = restante /5;
    restante = restante % 5;
    
    int moedas1 = restante;

    int total_moedas = moedas25 + moedas10 + moedas5 + moedas1;

    printf("O mínimo de moedas necessárias é: %d\n", total_moedas);

}