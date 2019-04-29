#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void inicializaAleatorio(int *vetor);
void imprimeVetor(int *vetor);
int main() {
    srand(time(NULL));
    int i, vet1[TAM], vet2[TAM], vet3[TAM];

    inicializaAleatorio(vet1);
    inicializaAleatorio(vet2);
    imprimeVetor(vet1);
    imprimeVetor(vet2);

    for (i = 0; i < TAM; ++i) {
        if (i % 2 == 0) vet3[i] = vet1[i];
        else vet3[i] = vet2[i];
    }
    imprimeVetor(vet3);

    return 0;
}

void inicializaAleatorio(int *vetor) {
    int i;
    for (i = 0; i < TAM; ++i) {
        vetor[i] = rand()%21 - 15;
    }
}

void imprimeVetor(int *vetor) {
    int i;
    for (i = 0; i < TAM; ++i) {
        printf("%3d ", vetor[i]);
    }
    printf("\n");
}
