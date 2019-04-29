#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void inicializaAleatorio(int *vetor);
void imprimeVetor(int *vetor, int tamanho);

int main() {
    srand(time(NULL));
    int vetor[N], vetorNovo[N-1], posicao, i;

    inicializaAleatorio(vetor);
    imprimeVetor(vetor, N);

    do {
        scanf("%d", &posicao);
    } while (posicao < 0 || posicao >= N);


    for (i = 0; i < posicao; i++) {
        vetorNovo[i] = vetor[i];
    }
    for (;i < N-1; i++) {
        vetorNovo[i] = vetor[i+1];
    }

    imprimeVetor(vetorNovo, N-1);

    return 0;
}

void inicializaAleatorio(int *vetor) {
    int i;
    for (i = 0; i < N; ++i) {
        vetor[i] = rand()%21 - 15;
    }
}

void imprimeVetor(int *vetor, int tamanho) {
    int i;
    for (i = 0; i < tamanho; ++i) {
        printf("%3d ", vetor[i]);
    }
    printf("\n");
}
