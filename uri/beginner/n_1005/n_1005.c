#include <stdio.h>

int main() {
    double in0, in1;
    scanf("%lf %lf", &in0, &in1);
    printf("MEDIA = %.5f\n", (in0 * 3.5 + in1 * 7.5) / 11.0);
    return 0;
}