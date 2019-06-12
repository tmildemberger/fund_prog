#include <stdio.h>
#include <stdlib.h>

#include "projetoImagens.h"

/*----------------------------------------------------------------------------*/
/** Negativo. Considera apenas o primeiro canal da imagem dada.
 *
 * Par�metros: Imagem* img: imagem a processar. Olhamos somente o 1o canal.
 *             Imagem* out: imagem de sa�da
 *
 * Valor de retorno: a sa�da esperada � armazenada em out. */
void negativo(Imagem* img, Imagem* out)
{
    unsigned int i, j;

    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++)
            out->dados[0][i][j] = 255 - img->dados[0][i][j];
}

/*----------------------------------------------------------------------------*/
/** Binariza��o. Considera apenas o primeiro canal da imagem dada.
 *
 * Par�metros: Imagem* img: imagem a binarizar. Olhamos somente o 1o canal.
 *             Imagem* out: imagem de sa�da. Processa apenas o 1o canal.
 *             unsigned char threshold: threshold.
 *
 * Valor de retorno: a sa�da esperada � armazenada em out. */

void binariza (Imagem* img, Imagem* out, unsigned char threshold) {

    unsigned int i, j;
    for (i = 0; i < img->altura; ++i) {
        for (j = 0; j < img->largura; ++j) {
            out->dados[0][i][j] = (img->dados[0][i][j] >= threshold)*255;
        }
    }
}

/*----------------------------------------------------------------------------*/
/** Filtro da média. Considera apenas o primeiro canal da imagem dada.
 *
 * Par�metros: Imagem* img: imagem a binarizar. Olhamos somente o 1o canal.
 *             Imagem* out: imagem de sa�da. Processa apenas o 1o canal.
 *             int winSize: tamanho da janela.
 *
 * Valor de retorno: a saída esperada � armazenada em out. */

void filtroMedia(Imagem* img, Imagem* out, unsigned int winSize) {
    unsigned int i, j;
    unsigned int tamBorda = (winSize - 1)/2;

    //prenche as linhas da borda da imagem

    for (i = 0; i < tamBorda; ++i) {
        for (j = 0; j < img->largura; ++j) {
            out->dados[0][i][j] = img->dados[0][i][j];
            out->dados[0][img->altura - 1 - i][j] = img->dados[0][img->altura - 1 - i][j];
        }
    }

    //prenche as colunas da borda da imagem

    for (j = 0; j < tamBorda; ++j) {
        for (i = tamBorda; i < img->altura - tamBorda; ++i) {
            out->dados[0][i][j] = img->dados[0][i][j];
            out->dados[0][i][img->largura - 1 - j] = img->dados[0][i][img->largura - 1 - j];
        }
    }

    //aplica o filtro

    for (i = tamBorda; i <  img->altura - tamBorda; ++i) {
        for (j = tamBorda; j < img->largura - tamBorda; ++j) {
            out->dados[0][i][j] = getMedia(img, winSize, i, j);
        }
    }
}

/*----------------------------------------------------------------------------*/
/** media dos elementos da matriz winSizexwinSize com elemento central img->dados[0][l][c]
 *
 * Par�metros: Imagem* img: imagem a binarizar. Olhamos somente o 1o canal.
 *             int winSize: tamanho da janela.
 *             int l, int c: coordenadas do centro da matriz
 * Valor de retorno: a média. */

int getMedia(Imagem* img, unsigned int winSize, int l, int c) {
    int media = 0;

    for(unsigned long int i=l-winSize/2; i<l+winSize/2; i++) {

        for(unsigned long int j=c-winSize/2; j<c+winSize/2; j++) {
            media += img->dados[0][i][j];
        }
    }

    media /= winSize*winSize;

    return media;
}
