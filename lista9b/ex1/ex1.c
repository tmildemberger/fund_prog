#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NL 5
#define NC 5

void preenche(int *m, int nl, int nc, int num);
void imprime(int *m, int nl, int nc);

int main() {
    srand(time(NULL));
    int matriz[NL][NC];
    preenche(matriz, NL, NC, 10);
    imprime(matriz, NL, NC);
    return 0;
}

void preenche(int *m, int nl, int nc, int num) {
    int i;
    for (i = 0; i < nl*nc; ++i) m[i] = rand() % num + 1;
}

void imprime(int *m, int nl, int nc) {
    int i;
    for (i = 0; i < nl*nc; ++i) {
        printf("%d ", m[i]);
        if ((i + 1) % nc == 0) printf("\n");
    }
}
