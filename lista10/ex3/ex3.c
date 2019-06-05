#include <stdio.h>
#include <stdlib.h>

#define TAM 8
int semRepeticoes(int v[], int tam, int **ret);
void imprimeVetor(int v[], int tam);

int main() {
    int vet[TAM] = { 0, 1, 2, 3, 4, 3, 2, 1 };
    int *sem, tamsem;
    tamsem = semRepeticoes(vet, TAM, &sem);
    imprimeVetor(sem, tamsem);
    printf("\n");
    return 0;
}

int semRepeticoes(int v[], int tam, int **ret) {
    int *coiso = (int*) malloc(sizeof *coiso * tam);
    int i, j, k = 0;
    for (i = 0; i < tam; ++i) {
        int jafiz = 0;
        for (j = i - 1; j >= 0; --j) {
            if (v[j] == v[i]) {
                jafiz = 1;
                break;
            }
        }
        if (!jafiz) {
            coiso[k++] = v[i];
        }
    }
    *ret = (int*) malloc(sizeof *ret * k);
    for (i = 0; i < k; ++i) {
        (*ret)[i] = coiso[i];
    }
    free(coiso);
    return k;
}

void imprimeVetor(int v[], int tam) {
    int i;
    for (i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
}
