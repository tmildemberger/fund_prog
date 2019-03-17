#include <stdio.h>

int main() {
    double in0, in1, in2;
    scanf("%lf %lf %lf", &in0, &in1, &in2);
    printf("MEDIA = %.1f\n", (in0 * 2 + in1 * 3 + in2 * 5) / 10.0);
    return 0;
}