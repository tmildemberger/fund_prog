#include <stdio.h>

int main() {
    int value;
    scanf("%d", &value);
    printf("%d\n", value);
    printf("%d nota(s) de R$ 100,00\n", value / 100);
    value %= 100;
    printf("%d nota(s) de R$ 50,00\n", value / 50);
    value %= 50;
    printf("%d nota(s) de R$ 20,00\n", value / 20);
    value %= 20;
    printf("%d nota(s) de R$ 10,00\n", value / 10);
    value %= 10;
    printf("%d nota(s) de R$ 5,00\n", value / 5);
    value %= 5;
    printf("%d nota(s) de R$ 2,00\n", value / 2);
    value %= 2;
    printf("%d nota(s) de R$ 1,00\n", value);
    return 0;
}