#include <stdio.h>
#define PRECO_GASOLINA 2.6
#define PRECO_POR_PEDAGIO 8.0
#define KM_POR_LITRO 15.0

int main() {
    int distancia, pedagios;
    printf("Digite a distancia (em km) entre as duas cidades: ");
    scanf("%d", &distancia);
    printf("Digite o numero de pedagios no percurso: ");
    scanf("%d", &pedagios);
    float preco_combustivel = PRECO_GASOLINA * distancia / KM_POR_LITRO;
    float preco_pedagio = PRECO_POR_PEDAGIO * pedagios;
    printf("O gasto total da viagem foi R$ %.2f\n", preco_combustivel + preco_pedagio);
    return 0;
}