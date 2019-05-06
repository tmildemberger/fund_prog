#include <stdio.h>
#define N 8

void analisaVetor(float v[], int tam, int *distintos);

int main() {
    float vet[N] = { -1.7, 3.0, 0.0, 3.0, 0.0, -1.7, 2.3, -1.7 };
    int n_distintos;
    analisaVetor(vet, N, &n_distintos);
    printf("Retorno: %d\n", n_distintos);
    return 0;
}

void analisaVetor(float v[], int tam, int *distintos) {
    int i;
    *distintos = 0;
    printf("Sequencia: ");
    for (i = 0; i < tam - 1; ++i) {
        printf("%.2f, ", v[i]);
    }
    printf("%.2f\n", v[i]);
    for (i = 0; i < tam; ++i) {
        int j, cont = 0, jafiz = 0;
        for (j = i - 1; j >= 0; --j) {
            if (v[j] == v[i]) {
                jafiz = 1;
                break;
            }
        }
        if (jafiz) continue;
        (*distintos)++;
        for (j = i; j < tam; ++j) {
            if (v[j] == v[i]) ++cont;
        }
        printf("%.2f ocorre %d vez(es)\n", v[i], cont);
    }
}
