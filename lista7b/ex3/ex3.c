#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void preencheVetor(int v[], int n);
void imprimeVetor(int v[], int n);
float mediaPares(int v[], int n);

int main() {
    srand(time(NULL));
    int vet[TAM];
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    printf("media dos elementos pares: %.2f\n", mediaPares(vet, TAM));
    return 0;
}

void preencheVetor(int v[], int n) {
    for (--n; n >= 0; --n) {
        v[n] = rand() % 71 - 9;
    }
}

void imprimeVetor(int v[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

float mediaPares(int v[], int n) {
    int soma = 0, c = 0;
    for (--n; n>=0; --n) {
        if (v[n] % 2 == 0) {
            soma += v[n];
            c++;
        }
    }
    return (float) soma / c;
}