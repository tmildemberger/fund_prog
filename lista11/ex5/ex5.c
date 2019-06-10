#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    int mat;
    char nome[51];
    int sup;
} Funcionario;

int indice_funcionario(Funcionario vet[], int n, int mat);
Funcionario* determinaSubordinado(Funcionario *vet[], int n, int mat, int *tam);

int indice_funcionario(Funcionario vet[], int n, int mat) {
    int i;
    for (i = 0; i < n; ++i) {
        if (vet[i].mat == mat) return i;
    }
    return -1;
}

Funcionario* determinaSubordinado(Funcionario *vet[], int n, int mat, int *tam) {
    int i;
    int n_subordinados = 0;
    for (i = 0; i < n; ++i) {
        if (vet[i]->sup == mat) ++n_subordinados;
    }
    Funcionario *subordinados = (Funcionario *) malloc(sizeof (Funcionario) * n_subordinados);
    for (i = 0, *tam = 0; i < n; ++i) {
        if (vet[i]->sup == mat) subordinados[(*tam)++] = *vet[i];
    }
    *tam = n_subordinados;
    return subordinados;
}

int main() {
    Funcionario funcs[6] = {{123, "Luiza", 125}, {124, "Diana", 129}, {125, "Gina", 126}, {126, "Dolores", -1}, {128, "Beatriz", 126}, {129, "Ana", 128}};
    int i;
    for (i = 0; i < 6; ++i) {
        printf("%d\n", funcs[i].mat);
    }
    Funcionario *vet[6];
    for (i = 0; i < 6; ++i) {
        vet[i] = &funcs[i];
    }
    printf("%d\n", indice_funcionario(funcs, 6, 128));
    printf("%d\n", indice_funcionario(funcs, 6, 171));
    int tam;
    Funcionario *subs = determinaSubordinado(vet, 6, 126, &tam);
    for (i = 0; i < tam; ++i) {
        printf("%d %s\n", subs[i].mat, subs[i].nome);
    }
    free(subs);
    return 0;
}
