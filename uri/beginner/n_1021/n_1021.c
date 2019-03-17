#include <stdio.h>
#include <math.h>

int main() {
    double value;
    scanf("%lf", &value);
    int cents = (int)(round(value * 100.0));
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", cents / 10000);
    cents %= 10000;
    printf("%d nota(s) de R$ 50.00\n", cents / 5000);
    cents %= 5000;
    printf("%d nota(s) de R$ 20.00\n", cents / 2000);
    cents %= 2000;
    printf("%d nota(s) de R$ 10.00\n", cents / 1000);
    cents %= 1000;
    printf("%d nota(s) de R$ 5.00\n", cents / 500);
    cents %= 500;
    printf("%d nota(s) de R$ 2.00\n", cents / 200);
    cents %= 200;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", cents / 100);
    cents %= 100;
    printf("%d moeda(s) de R$ 0.50\n", cents / 50);
    cents %= 50;
    printf("%d moeda(s) de R$ 0.25\n", cents / 25);
    cents %= 25;
    printf("%d moeda(s) de R$ 0.10\n", cents / 10);
    cents %= 10;
    printf("%d moeda(s) de R$ 0.05\n", cents / 5);
    cents %= 5;
    printf("%d moeda(s) de R$ 0.01\n", cents);
    return 0;
}