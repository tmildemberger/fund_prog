#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NL 5
#define NC 5

void preenche(int *m, int nl, int nc, int num);
void imprime(int *m, int nl, int nc);

int soma_superior(int *m, int nl, int nc);
int soma_inferior(int *m, int nl, int nc);
int soma_principal(int *m, int nl, int nc);
int soma_secundaria(int *m, int nl, int nc);

int main() {
    srand(time(NULL));
    int matriz[NL][NC];
    preenche(matriz, NL, NC, 2);
    imprime(matriz, NL, NC);
    printf("soma trig superior: %d\n", soma_superior(matriz, NL, NC));
    printf("soma trig inferior: %d\n", soma_inferior(matriz, NL, NC));
    printf("soma diag principal: %d\n", soma_principal(matriz, NL, NC));
    printf("soma diag secundaria: %d\n", soma_secundaria(matriz, NL, NC));
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

int soma_superior(int *m, int nl, int nc) {
    int i, j, soma = 0;
    for (i = 0; i < nl; ++i) {
        for (j = i; j < nc; ++j) {
            soma += m[i * nc + j];
        }
    }
    return soma;
}

int soma_inferior(int *m, int nl, int nc) {
    int i, j, soma = 0;
    for (i = 0; i < nl; ++i) {
        for (j = i; j >= 0; --j) {
            soma += m[i * nc + j];
        }
    }
    return soma;
}

int soma_principal(int *m, int nl, int nc) {
    int i, soma = 0;
    for (i = 0; i < nl && i < nc; ++i) {
        soma += m[i * (nc + 1)];
    }
    return soma;
}

int soma_secundaria(int *m, int nl, int nc) {
    int i, soma = 0;
    for (i = 0; i < nl && i < nc; ++i) {
        soma += m[(nc - 1) * (i + 1)];
    }
    return soma;
}
