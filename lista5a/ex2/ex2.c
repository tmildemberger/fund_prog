#include <stdio.h>

int binario2Decimal(int valor);

int main() {
    int binario;
    scanf("%d", &binario);
    printf("0b%d == %d\n", binario, binario2Decimal(binario));
    return 0;
}

int binario2Decimal(int valor) {
    int exp2 = 1;
    int decimal = 0;
    while (valor > 0) {
        decimal += (valor % 10) * exp2;
        valor /= 10;
        exp2 *= 2;
    }
    return decimal;
}
