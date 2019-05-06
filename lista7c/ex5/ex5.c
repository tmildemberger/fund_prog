#include <stdio.h>

#define TAM 5

int subVetor(int *v, int tam, int *i, int *j);
int main() {
    int v[TAM] = {4, 2, -3, 1, 6}, i, j;
    if (subVetor(v, TAM, &i, &j)) printf("%d - %d\n", i, j);
    else printf("nao\n");
    return 0;
}

int subVetor(int *v, int tam, int *i, int *j) {
    int soma;
    for(*i = 0; *i < tam; (*i)++) {
        soma = 0;
        for(*j = *i; *j < tam; (*j)++) {
            soma += v[*j];
            if (soma == 0) return 1;

        }
    }
    return 0;
}
