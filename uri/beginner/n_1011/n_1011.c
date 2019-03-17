#include <stdio.h>
#define PI 3.14159

int main() {
    double radius;
    scanf("%lf", &radius);
    printf("VOLUME = %.3f\n", 4.0 / 3.0 * PI * radius * radius * radius);
    return 0;
}