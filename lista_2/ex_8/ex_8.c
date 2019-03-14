#include <stdio.h>

int main() {
    float celsius;
    printf("Digite uma temperatura em graus Celsius: ");
    scanf("%f", &celsius);
    printf("Em graus Fahrenheit: %f\n", celsius * 9.0 / 5.0 + 32.0);
    return 0;
}