#include <stdio.h>

int main() {
    int quantos;
    scanf("%d", &quantos);

    int multiplo = 1, i;
    for (i = 1; i <= quantos; ++i) {
        multiplo *= i;
        int menor_ok = multiplo;
        while (multiplo >= quantos) {
            int ok = 1, j;
            for (j = 1; j <= i; ++j) {
                if (multiplo % j != 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                menor_ok = multiplo;
            }
            --multiplo;
        }
        multiplo = menor_ok;
    }
    printf("%d e o menor numero divisivel por todos os numeros entre 1 e %d\n", multiplo, quantos);
    return 0;
}