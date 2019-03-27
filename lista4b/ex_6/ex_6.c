#include <stdio.h>

int main() {
    int valores, n, impares, ultimo = -1;
    scanf("%d", &valores);
    for (n = 1; n <= valores; ++n) {
        printf("%d^3 = 0 ", n);
        for (impares = 0; impares < n; ++impares) {
            ultimo += 2;
            printf("+ %d ", ultimo);
        }
        printf("\n");
    }
    return 0;
}
