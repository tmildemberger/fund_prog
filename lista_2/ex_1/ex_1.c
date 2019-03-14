#include <stdio.h>

int main() {
    float base, altura;

    printf("Digite a base e a altura do seu retangulo: ");
    scanf("%f %f", &base, &altura);

    float perimetro = 2 * base + 2 * altura;
    printf("O perimetro e: %f\n", perimetro);
    return 0;
}