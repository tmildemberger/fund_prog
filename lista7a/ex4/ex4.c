#include <stdio.h>

#define N_LADOS 6

int main() {
    int lancamentos, face[N_LADOS] = {0};
    scanf("%d", &lancamentos);
    int i;
    for (i = 0; i < lancamentos; ++i) {
        int resultado;
        scanf("%d", &resultado);
        face[resultado - 1]++;
    }
    for (i = 0; i < N_LADOS; ++i) {
        printf("a face %d ocorreu %d vezes\n", i + 1, face[i]);
    }
    return 0;
}
