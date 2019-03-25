#include <stdio.h>

int main() {
    int mes;
    float dinheiro, imposto = 0.0;
    scanf("%d %f", &mes, &dinheiro);
    if (mes <= 3) {
        if (dinheiro > 3743.19) {
            imposto += (dinheiro - 3743.19) * 0.275;
            dinheiro = 3743.19;
        }
        if (dinheiro > 2995.71) {
            imposto += (dinheiro - 2995.71) * 0.225;
            dinheiro = 2995.71;
        }
        if (dinheiro > 2246.76) {
            imposto += (dinheiro - 2246.76) * 0.15;
            dinheiro = 2246.76;
        }
        if (dinheiro > 1499.16) {
            imposto += (dinheiro - 1499.16) * 0.075;
            dinheiro = 1499.16;
        }
    } else {
        if (dinheiro > 3911.63) {
            imposto += (dinheiro - 3911.63) * 0.275;
            dinheiro = 3911.63;
        }
        if (dinheiro > 3130.52) {
            imposto += (dinheiro - 3130.52) * 0.225;
            dinheiro = 3130.52;
        }
        if (dinheiro > 2347.87) {
            imposto += (dinheiro - 2347.87) * 0.15;
            dinheiro = 2347.87;
        }
        if (dinheiro > 1566.62) {
            imposto += (dinheiro - 1566.62) * 0.075;
            dinheiro = 1566.62;
        }
    }
    printf("O valor a ser pago de IR e %.2f\n", imposto);
    return 0;
}