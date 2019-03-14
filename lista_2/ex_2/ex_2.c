#include <stdio.h>
#define PI 3.14159

int main() {
    float raio;

    printf("Digite o raio da sua esfera: ");
    scanf("%f", &raio);

    float volume = 4.0 / 3.0 * PI * raio * raio * raio;
    printf("O volume e: %f\n", volume);
    return 0;
}