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
