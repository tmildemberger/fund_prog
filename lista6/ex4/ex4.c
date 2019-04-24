#include <stdio.h>

int divide(int *m, int *n, int d);
int mmc(int m, int n);

int main() {
    int n1, n2, mm;
    scanf("%d %d", &n1, &n2);
    mm = mmc(n1, n2);
    printf("%d\n", mm);
    return 0;
}

int divide(int *m, int *n, int d) {
    int div_algum = 0;
    if ((*m) % d == 0) {
        (*m) /= d;
        div_algum = 1;
    }
    if ((*n) % d == 0) {
        (*n) /= d;
        div_algum = 1;
    }
    return div_algum;
}

int mmc(int m, int n) {
    int div = 2, minimo = 1;
    while (m != 1 || n != 1) {
        while (divide(&m, &n, div)) {
            minimo *= div;
        }
        div++;
    }
    return minimo;
}
