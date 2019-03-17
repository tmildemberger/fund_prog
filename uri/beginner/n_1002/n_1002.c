#include <stdio.h>
#define PI 3.14159

int main() {
    double radius;
    scanf("%lf", &radius);
    printf("A=%.4f\n", PI * radius * radius);
    return 0;
}