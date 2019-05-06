#include <stdio.h>
#include <limits.h>

#define TAM 8

void doisMaiores(int v[], int tam, int *maior, int *segundoMaior);

int main() {
    int vet[TAM] = { 8, 5, 2, 9, 11, 10, 3, 3 };
    //int vet[TAM] = { 8, 5, 5, 5, 5, 5, 5, 5 };
    int maior, segMaior;
    doisMaiores(vet, TAM, &maior, &segMaior);
    printf("maior = %d\nsegundo maior = %d\n", maior, segMaior);
    return 0;
}

void doisMaiores(int v[], int tam, int *maior, int *segundoMaior) {
    //*maior = v[0];
    *maior = INT_MIN;
    *segundoMaior = INT_MIN;
    int i;
    for (i = 0; i < tam; ++i) {
        if (v[i] > *maior) {
            *segundoMaior = *maior;
            *maior = v[i];
        }
        else if (v[i] > *segundoMaior) *segundoMaior = v[i];
    }
}
