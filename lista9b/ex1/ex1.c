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
    // int (*linha)[NC] = &matriz;
    preenche(&matriz[0][0], NL, NC, 10);
    imprime(&matriz[0][0], NL, NC);
    return 0;
}

void preenche(int *m, int nl, int nc, int num) {
    int i;
    int (*mat)[nc] = (int (*)[nc])m; int j;
    for (i = 0; i < nl; ++i)
        for (j = 0; j < nc; ++j) mat[i][j] = rand() % num + 1;
    // for (i = 0; i < nl*nc; ++i) m[i] = rand() % num + 1;
}

void imprime(int *m, int nl, int nc) {
    int i;
    for (i = 0; i < nl*nc; ++i) {
        printf("%2d ", m[i]);
        if ((i + 1) % nc == 0) printf("\n");
    }
}
