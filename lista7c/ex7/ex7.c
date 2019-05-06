#include <stdio.h>

#define TAM 10

int tiraDuplicados(int *v, int tam);
void copiarVetor(int *v1, int tam1, int *v2);
void intersecao(int *v1, int tam1, int *v2, int tam2, int *v3, int *tam3);
void exclusao(int *v1, int tam1, int *v2, int tam2, int *v3, int *tam3);
void uniao(int *v1, int tam1, int *v2, int tam2, int *v3, int *tam3);

int main() {
    int tam1 = TAM, tam2 = TAM, tamRes;
    int vet1[TAM] = {1,2,3,6,5,4,9,8,7,0};
    int vet2[TAM] = {1,2,3,5,5,5,-2, -3, 7, -12};
    int vet3[TAM];
    intersecao(vet1,tam1,vet2,tam2,vet3,&tamRes);
    int i;
    for(i = 0; i < tamRes; i++) printf("%d ", vet3[i]);
    printf("\n");

    int vet4[2*TAM];
    exclusao(vet1,tam1,vet2,tam2,vet4,&tamRes);
    for(i = 0; i < tamRes; i++) printf("%d ", vet4[i]);
    printf("\n");

    uniao(vet1,tam1,vet2,tam2,vet4,&tamRes);
    for(i = 0; i < tamRes; i++) printf("%d ", vet4[i]);
    printf("\n");

    return 0;
}

int tiraDuplicados(int *v, int tam) {
    int nRestante = tam, i, j, k;
    for (i = tam-1; i > 0; i--) {

        for(j = i - 1; j > 0; j--) {
            if (v[i] == v[j]) {

                nRestante--;
                for (k = i; k < nRestante; k ++) {
                    v[k] = v[k+1];
                }
            }
        }
    }
    return nRestante;
}

void copiarVetor(int *v1, int tam1, int *v2) {
    int i;
    for (i = 0; i < tam1; i++) v2[i] = v1[i];

}

void intersecao(int *v1, int tam1, int *v2, int tam2, int *v3, int *tam3) {
    int v1aux[TAM], v2aux[TAM];
    copiarVetor(v1, tam1, v1aux);
    copiarVetor(v2, tam2, v2aux);
    *tam3 = 0;

    tam1 = tiraDuplicados(v1aux, tam1);
    tam2 = tiraDuplicados(v2aux, tam2);
    int i, j;
    for (i = 0; i < tam1; i++) {

        for(j = 0; j < tam2; j++) {
            if (v1aux[i] == v2aux[j]) {
                v3[*tam3] = v1aux[i];
                (*tam3)++;
            }
        }
    }
}
void exclusao(int *v1, int tam1, int *v2, int tam2, int *v3, int *tam3){
    int v1aux[TAM], v2aux[TAM];
    copiarVetor(v1, tam1, v1aux);
    copiarVetor(v2, tam2, v2aux);
    *tam3 = 0;

    tam1 = tiraDuplicados(v1aux, tam1);
    tam2 = tiraDuplicados(v2aux, tam2);
    int i, j, estaEmAmbos;
    for (i = 0; i < tam1; i++) {

        estaEmAmbos = 0;
        for(j = 0; j < tam2; j++) {
            if (v1aux[i] == v2aux[j]) estaEmAmbos = 1;
        }

        if(!estaEmAmbos) {
            v3[*tam3] = v1aux[i];
            (*tam3)++;
        }

    }

    for (i = 0; i < tam2; i++) {
        estaEmAmbos = 0;
        for(j = 0; j < tam1; j++) {
            if (v2aux[i] == v1aux[j]) estaEmAmbos = 1;
        }

        if(!estaEmAmbos) {
            v3[*tam3] = v2aux[i];
            (*tam3)++;
        }
    }
}
void uniao(int *v1, int tam1, int *v2, int tam2, int *v3, int *tam3){

    copiarVetor(v1, tam1, v3);
    copiarVetor(v2, tam2, v3 + tam1);
    *tam3 = tiraDuplicados(v3,tam1+tam2);
}
