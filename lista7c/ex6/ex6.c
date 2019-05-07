#include <stdio.h>

#define TAM 2

int segmentoSomaMax(int v[], int tam, int *st, int *ed);

int main() {
    //int vet[TAM] = { 5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1 };
    int vet[TAM] = { -1, -2 };
    int i, tam;
    int soma = segmentoSomaMax(vet, TAM, &i, &tam);
    for (; i < tam - 1; ++i) {
        printf("%d + ", vet[i]);
    }
    printf("%d = %d\n", vet[i], soma);
    return 0;
}

int segmentoSomaMax(int v[], int tam, int *st, int *ed) {
    int t_seg, maior_soma = v[0];
    *st = 0;
    *ed = 1;
    for (t_seg = 1; t_seg <= tam; ++t_seg) {
        int i;
        for (i = 0; i <= tam - t_seg; ++i) {
            int soma = 0, j;
            for (j = i; j < i + t_seg; ++j) {
                soma += v[j];
            }
            if (soma > maior_soma) {
                maior_soma = soma;
                *st = i;
                *ed = j;
            }
        }
    }
    return maior_soma;
}
