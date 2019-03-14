#include <stdio.h>

int main() {
    int valor;
    printf("Digite quantos reais deseja trocar: ");
    scanf("%d", &valor);
    printf("R$ %d = ", valor);
    printf("%d cedulas de 50 reais, ", valor / 50);
    valor %= 50;
    printf("%d cedulas de 5 reais, ", valor / 5);
    valor %= 5;
    printf("e %d cedulas de 1 real\n", valor);
    return 0;
}