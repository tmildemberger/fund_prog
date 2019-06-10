#include <stdio.h>

#define TAM 5

typedef struct aniversariante {
    char nome[64];
    int dia_aniv;
    int mes_aniv;
} Aniversariante;

int main() {
    Aniversariante anivs[TAM];
    int i;
    for (i = 0; i < TAM; ++i) {
        scanf("%s %d %d", anivs[i].nome, &(anivs[i].dia_aniv),
                                          &anivs[i].mes_aniv);
    }
    for (i = 1; i <= 12; ++i) {
        int j;
        printf("Aniversariantes do mes %d:\n", i);
        for (j = 0; j < TAM; ++j) {
            if (anivs[j].mes_aniv == i) {
                printf("%s\n", anivs[j].nome);
            }
        }
        printf("\n");
    }
    return 0;
}
