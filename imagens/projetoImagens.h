#ifndef __PROJETOIMAGENS_H
#define __PROJETOIMAGENS_H
#include "imagem.h"

void negativo(Imagem* img, Imagem* out);
void binariza(Imagem* img, Imagem* out, unsigned char threshold);
void filtroMedia(Imagem* img, Imagem* out, unsigned int winSize);
int getMedia(Imagem* img, unsigned int winSize, int l, int c);
// colocar tamb�m o prot�tipo para a fun��o que computa os componentes conexos.
#endif
