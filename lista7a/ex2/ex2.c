#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30

int main() {
    srand(time(NULL));
    int i, vet[TAM];
    for (i = 0; i < TAM; ++i) {
        vet[i] = rand()%10;
    }
    for (i = 0; i < TAM; ++i) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    for (i = 0; i < TAM / 2; ++i) {
        int aux = vet[i];
        vet[i] = vet[TAM-i-1];
        vet[TAM-i-1] = aux;
    }
    for (i = TAM-1; i >= 0; --i) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    return 0;
}
