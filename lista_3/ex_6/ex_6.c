#include <stdio.h>

int main() {
    float saldo_medio, credito;
    printf("Digite o valor do saldo medio: ");
    scanf("%f", &saldo_medio);
    if (saldo_medio > 600) {
        credito = 0.4 * saldo_medio;
    } else if (saldo_medio >= 401) {
        credito = 0.3 * saldo_medio;
    } else if (saldo_medio >= 201) {
        credito = 0.2 * saldo_medio;
    } else {
        credito = 0.0;
    }
    printf("Seu credito e %.2f\n", credito);
    return 0;
}
