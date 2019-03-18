#include <stdio.h>

int main() {
    float a, b, c;
    printf("Digite tres valores de ponto flutuante: ");
    scanf("%f %f %f", &a, &b, &c);

    if (b > a && b > c) {
        float temp = a;
        a = b;
        b = temp;
    } else if (c > a) {
        float temp = a;
        a = c;
        c = temp;
    }
    if (a >= b + c || a == 0 || b == 0 || c == 0) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        if (a * a == b * b + c * c) {
            printf("TRIANGULO RETANGULO\n");
        } else if (a * a > b * b + c * c) {
            printf("TRIANGULO OBTUSANGULO\n");
        } else {
            printf("TRIANGULO ACUTANGULO\n");
        }
        if (a == b && b == c) {
            printf("TRIANGULO EQUILATERO\n");
        } else if (!(a != b && a != c && b != c)) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    return 0;
}
