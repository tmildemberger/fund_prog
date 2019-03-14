#include <stdio.h>

int main() {
    int distancia;
    float combustivel;
    printf("Digite a distancia percorrida em km: ");
    scanf("%d", &distancia);
    printf("Digite o combustivel gasto em L: ");
    scanf("%f", &combustivel);
    printf("Seu carro andou %.3f km/L\n", distancia / combustivel);
    return 0;
}