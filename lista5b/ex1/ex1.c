#include <stdio.h>

float absd(float x);
int sinal(float x);
int arredonda (float x);

int main() {
    float x = 0.0f;
    while (x < 1000.0f) {
        scanf("%f", &x);
        printf("%d\n", arredonda(x));
    }
    return 0;
}

float absd(float x) {
    if (x >= 0) return x;
    else return -x;
}

int sinal(float x) {
    return absd(x) / x;
}

int arredonda (float x) {
    return (int) x + sinal(x) * ( absd(x - (int) x) >= 0.5);
}
