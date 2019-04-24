#include <stdio.h>
#include <math.h>

void calcula_raizes(float a, float b, float c, float *x1, float *x2);
void calcula_raizes(float a, float b, float c, float *x1, float *x2) {
    (*x1) = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    (*x2) = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    float r1, r2;
    calcula_raizes(a, b, c, &r1, &r2);
    printf("raizes %f %f\n", r1, r2);
    return 0;
}
