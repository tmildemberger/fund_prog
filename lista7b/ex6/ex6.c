#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 8

void preencheVetor(int v[], int n);
void imprimeVetor(int v[], int n);

void intercalaVetores(int v1[], int v2[], int v3[], int n);

int main() {
    srand(time(NULL));
    int vet1[TAM];
    int vet2[TAM];
    int vet3[TAM];
    preencheVetor(vet1, TAM);
    preencheVetor(vet2, TAM);
    imprimeVetor(vet1, TAM);
    imprimeVetor(vet2, TAM);
    
    intercalaVetores(vet1, vet2, vet3, TAM);
    imprimeVetor(vet3, TAM);
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

void intercalaVetores(int v1[], int v2[], int v3[], int n) {
    for (--n; n >= 0; --n) {
        if (n % 2) {
            v3[n] = n[v2];
        } else {
            n[v3] = v1[n];
        }
    }
}