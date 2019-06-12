#ifndef __PROJETOIMAGENS_H
#define __PROJETOIMAGENS_H
#include "imagem.h"

void negativo(Imagem* img, Imagem* out);
void binariza(Imagem* img, Imagem* out, unsigned char threshold);
void filtroMedia(Imagem* img, Imagem* out, int winSize);

// colocar também o protótipo para a função que computa os componentes conexos.
#endif
