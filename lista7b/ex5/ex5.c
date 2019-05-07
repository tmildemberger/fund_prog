#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30000

void preencheVetor(int v[], int n);
void imprimeVetor(int v[], int n);

void ordenaCrescente(int v[], int n);

int main() {
    srand(time(NULL));
    int vet[TAM];
    
    preencheVetor(vet, TAM);
    // imprimeVetor(vet, TAM);
    
    printf("ordenando...\n");
    ordenaCrescente(vet, TAM);
    
    // imprimeVetor(vet, TAM);
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

void ordenaCrescente(int v[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        int j = i - 1;
        int num = v[i];
        for (;j >= 0 && v[j] > num; --j) {
            v[j + 1] = v[j];
        }
        v[j + 1] = num;
    }
}