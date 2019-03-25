#include <stdio.h>

int main() {
    int i, positivos = 0;
    float num, soma = 0;
    for (i = 0; i < 6; ++i) {
        scanf("%f", &num);
        if (num > 0) {
            ++positivos;
            soma += num;
        }
    }
    printf("%d valores positivos\n", positivos);
    printf("Media dos positivos: %.1f\n", soma / positivos);
    return 0;
}
