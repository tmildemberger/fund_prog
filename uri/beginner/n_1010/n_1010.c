#include <stdio.h>

int main() {
    int units_1, units_2;
    double price_1, price_2;
    scanf("%*d %d %lf", &units_1, &price_1);
    scanf("%*d %d %lf", &units_2, &price_2);
    printf("VALOR A PAGAR: R$ %.2f\n", price_1 * units_1 + price_2 * units_2);
    return 0;
}