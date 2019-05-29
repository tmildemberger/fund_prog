#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NL 3
#define NC 3

void preenche(int *m, int nl, int nc, int num);
void imprime(int *m, int nl, int nc);
void mul(int *a, int al, int ac, int *b, int bl, int bc, int *c);
void copiar(int *a, int al, int ac, int *b);

int main() {
    srand(time(NULL));
    int a[NL][NC], b[NL][NC], c[NL][NC];

    preenche(a, NL, NC, 10);
    preenche(b, NL, NC, 10);

    printf("A = \n");
    imprime(a, NL, NC);

    printf("\nB = \n");
    imprime(b, NL, NC);

    printf("\nA * B =\n");
    mul(a, NL, NC, b, NL, NC, c);
    imprime(c, NL, NC);

    printf("\nA^2 = \n");
    mul(a, NL, NC, a, NL, NC, c);
    imprime(c, NL, NC);

    int n, i;

    printf("\nA^");
    scanf("%d", &n);
    printf(" = \n");
    int d[NL][NC];
    copiar(c, NL, NC, d);
    for(i = 2; i < n; ++i) {
        mul(c, NL, NC, a, NL, NC, d);
        copiar(d, NL, NC, c);
    }

    imprime(d, NL, NC);


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

void mul(int *a, int al, int ac, int *b, int bl, int bc, int *c) {
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
