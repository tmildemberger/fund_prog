#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 4

void preencheVetor(int v[], int n);
void imprimeVetor(int v[], int n);

int e_permutacao(int v1[], int v2[], int n);

int main() {
    srand(time(NULL));
    int vet1[TAM] = { 0 };
    int vet2[TAM] = { 0 };
    preencheVetor(vet1, TAM);
    preencheVetor(vet2, TAM);
    imprimeVetor(vet1, TAM);
    imprimeVetor(vet2, TAM);
    if (e_permutacao(vet1, vet2, TAM)) {
        printf("e permutacao\n");
        return 1;
    } else {
        printf("nao\n");
        return 0;
    }
    // return 0;
}

void preencheVetor(int v[], int n) {
    for (--n; n >= 0; --n) {
        // v[n] = rand() % 71 - 9;
        v[n] = rand() % TAM;
    }
}

void imprimeVetor(int v[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int e_permutacao(int v1[], int v2[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        int j, c = 0;
        for (j = 0; j < n; ++j) {
            if (v1[i] == v1[j]) c++;
        }
        for (j = 0; j < n; ++j) {
            if (v2[j] == v1[i]) c--;
        }
        if (c != 0) {
            return 0;
        }
    }
    return 1;
}