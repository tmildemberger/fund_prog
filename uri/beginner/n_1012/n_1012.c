#include <stdio.h>
#define PI 3.14159

int main() {
    double inA, inB, inC;
    scanf("%lf %lf %lf", &inA, &inB, &inC);
    printf("TRIANGULO: %.3f\n", inA * inC / 2.0);
    printf("CIRCULO: %.3f\n", PI * inC * inC);
    printf("TRAPEZIO: %.3f\n", (inA + inB) * inC / 2.0);
    printf("QUADRADO: %.3f\n", inB * inB);
    printf("RETANGULO: %.3f\n", inA * inB);
    return 0;
}