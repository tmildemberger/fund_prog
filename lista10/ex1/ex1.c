#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* alocaVetor(int tam);
void preencheAleatorio(int v[], int tam);
void imprimeVetor(int v[], int tam);

int main() {
    srand(time(NULL));
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int *v1 = alocaVetor(n1);
    preencheAleatorio(v1, n1);
    int *v2 = alocaVetor(n2);
    preencheAleatorio(v2, n2);

    int n3 = (n1 < n2) ? n1 : n2;
    int *v3 = alocaVetor(n3);
    int i;
    for (i = 0; i < n3; ++i) {
        v3[i] = v1[i] * v2[i];
    }
    imprimeVetor(v1, n1);
    printf("\n");
    imprimeVetor(v2, n2);
    printf("\n");
    imprimeVetor(v3, n3);
    printf("\n");

    free(v1);
    free(v2);
    free(v3);
    return 0;
}

int* alocaVetor(int tam) {
    return malloc(sizeof (int) * tam);
}

void preencheAleatorio(int v[], int tam) {
    int i;
    for (i = 0; i < tam; ++i) {
        v[i] = rand() % 11;
    }
}

void imprimeVetor(int v[], int tam) {
    int i;
    for (i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
}
