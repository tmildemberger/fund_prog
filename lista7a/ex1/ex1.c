#include <stdio.h>

#define N 5

int main() {
    int vetor[N], i, j, aux;
    for (i = 0; i < 5; i++ ) {
        scanf("%d", &vetor[i]);
    }
    scanf("%d %d", &i, &j);

    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;

    return 0;
}
