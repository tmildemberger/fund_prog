#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30

int main() {
    srand(time(NULL));
    int i, vet[TAM];
    for (i = 0; i < TAM; ++i) {
        vet[i] = rand()%21 - 15;
    }
    int valor;
    scanf("%d", &valor);

    for (i = 0; i < TAM; i++) {
        if (valor == vet[i]) {
            printf("ACHEI\n");
            return 0;
        }
    }
    printf("NAO ACHEI\n");
    return 0;
}
