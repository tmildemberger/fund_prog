#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void preencheVetor(int v[], int n);
void imprimeVetor(int v[], int n);
float mediaParesMaiorMenor(int v[], int n, int *maior, int *menor);

int main() {
    srand(time(NULL));
    int vet[TAM];
    int maior, menor;
    preencheVetor(vet, TAM);
    imprimeVetor(vet, TAM);
    float media = mediaParesMaiorMenor(vet, TAM, &maior, &menor);
    printf("media dos elementos pares: %.2f\n", media);
    printf("maior elemento: %d\nmenor elemento: %d\n", maior, menor);
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

float mediaParesMaiorMenor(int v[], int n, int *maior, int *menor) {
    int soma = 0, c = 0;
    0[maior] = v[0];
    menor[0] = 0[v];
    for (--n; n>=0; --n) {
        if (v[n] % 2 == 0) {
            soma += v[n];
            c++;
        }
        if (n[v] > maior[0]) {
            *maior = v[n];
        } else if (v[n] < *menor) {
            0[menor] = n[v];
        }
    }
    return (float) soma / c;
}