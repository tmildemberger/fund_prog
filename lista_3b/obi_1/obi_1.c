#include <stdio.h>

int main() {
    int consumo;
    int preco = 0;
    printf("Digite o consumo de agua em m^3: ");
    scanf("%d", &consumo);
    if (consumo > 100) {
        preco += (consumo - 100) * 5;
        consumo = 100;
    }
    if (consumo > 30) {
        preco += (consumo - 30) * 2;
        consumo = 30;
    }
    if (consumo > 10) {
        preco += consumo - 10;
    }
    preco += 7;
    printf("O preco da conta de agua sera %d\n", preco);
    return 0;
}