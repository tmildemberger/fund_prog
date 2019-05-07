#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void preencheVetor(int v[], int n);
void imprimeVetorDireto(int v[], int n);
void imprimeVetorContrario(int v[], int n);

int main() {
    srand(time(NULL));
    int vet[TAM];
    preencheVetor(vet, TAM);
    imprimeVetorDireto(vet, TAM);
    imprimeVetorContrario(vet, TAM);
    return 0;
}

void preencheVetor(int v[], int n) {
    for (--n; n >= 0; --n) {
        v[n] = rand() % 71 - 9;
    }
}

void imprimeVetorDireto(int v[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void imprimeVetorContrario(int v[], int n) {
    for (--n; n >= 0; --n) {
        printf("%d ", v[n]);
    }
    printf("\n");
}