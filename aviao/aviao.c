#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void preenche_simetrica(int *m, int n);
void imprime(int *m, int nl, int nc);
void mul(int *a, int al, int ac, int *b, int bl, int bc, int *c);
void copiar(int *a, int al, int ac, int *b);
int linhaMax(int *a, int nl, int nc);

int main() {
    srand(time(NULL));
    int adjacencia[N][N];

    preenche_simetrica(&adjacencia[0][0], N);

    printf("adjacencia = \n");
    imprime(&adjacencia[0][0], N, N);

    int i, j, k, n;
    int d[N][N], caminhos[N][N];
    scanf("%d %d %d", &i, &j, &n);
    if(adjacencia[i][j]) printf("E possivel ir direto!\n");
    else printf("Nao e possivel ir direto!\n");

    copiar(&adjacencia[0][0], N, N, &caminhos[0][0]);
    for(k = 1; k <= n; ++k) {
        mul(&adjacencia[0][0], N, N, &caminhos[0][0], N, N, &d[0][0]);
        copiar(&d[0][0], N, N, &caminhos[0][0]);
        printf("Existem %d caminhos com %d conexoes\n", caminhos[i][j], k);
    }
    return 0;
}

void preenche_simetrica(int *m, int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
            if (i == j) m[i * n + j] = 0;
            else {
                int val = (rand() % 100) < (200 / n);
                m[i * n + j] = val;
                m[j * n + i] = val;
            }
        }
    }
}

void imprime(int *m, int nl, int nc) {
    int i;
    for (i = 0; i < nl*nc; ++i) {
        printf("%d ", m[i]);
        if ((i + 1) % nc == 0) printf("\n");
    }
}

void mul(int *a, int al, int ac, int *b, int bl, int bc, int *c) {
    ac = bl;
    int i, j, k;
    for (i = 0; i < al; ++i){
        for(j = 0; j < bc; ++j){
            c[i*ac+j] = 0;
            for(k = 0; k < ac; ++k) {
                c[i*ac+j] += a[i*ac + k]*b[k*bc + j];
            }
        }
    }
}

void copiar(int *a, int al, int ac, int *b){
    int i;
    for (i = 0; i < al*ac; ++i) {
        b[i] = a[i];
    }
}

int linhaMax(int *a, int nl, int nc) {
    int i, j, soma, maiorSoma = 0, indice = 0;
    for (i = 0; i < nl; ++i) {
        soma = 0;
        for (j = 0; j < nc; ++j) {
            soma += a[i*nc + j];
        }
        if (soma > maiorSoma) {
            indice = i;
            maiorSoma = soma;
        }
    }
    return indice;
}
