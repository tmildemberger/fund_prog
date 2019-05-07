#include <stdio.h>

#define TAM 5

void imprimePares(int *v, int tam, int num);

int main() {
    int num, v[TAM];
    scanf("%d", &num);
    int i;
    for(i = 0; i < TAM; i++) scanf("%d", (v+i));

    imprimePares(v, TAM, num);

    return 0;
}

void imprimePares(int *v, int tam, int num) {
    int i, j;
    for (i = 0; i < tam; i++) {
        for(j = i + 1; j < tam; j++) {
            if (v[i] + v[j] == num) printf("(%d) + (%d)\n", v[i], v[j]);
        }

    }

}
