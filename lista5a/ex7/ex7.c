#include <stdio.h>

int primoMaior(int n);
int ePrimo(int possivel);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d <= %d\n", primoMaior(n), n);
    return 0;
}

int primoMaior(int n) {
    int talvezprimo = n;
    while (talvezprimo > 1) {
        if (ePrimo(talvezprimo)) return talvezprimo;
        --talvezprimo;
    }
    return -1;
}

int ePrimo(int possivel) {
    int div;
    for (div = 2; div < possivel / 2; ++div) {
        if (possivel % div == 0) {
            return 0;
        }
    }
    return 1;
}
