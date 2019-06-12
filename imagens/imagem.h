/*============================================================================*/
/* UM TIPO PARA MANIPULA��O DE ARQUIVOS BMP                                   */
/*----------------------------------------------------------------------------*/
/* Autor: Bogdan T. Nassu - nassu@dainf.ct.utfpr.edu.br                       */
/*============================================================================*/
/** Este arquivo traz declara��es de um tipo e rotinas para manipula��o de
 * arquivos bmp. Como temos um prop�sito puramente did�tico, apenas um sub-
 * conjunto m�nimo do formato foi implementado. Matrizes s�o usadas para
 * representar os dados. Vetores seriam computacionalmente mais eficientes, mas
 * aqui procuramos priorizar a clareza e a facilidade de uso. */
/*============================================================================*/

#ifndef __IMAGEM_H
#define __IMAGEM_H

/*============================================================================*/

#define CANAL_R 0 /* Constante usada para se referir ao canal vermelho. */
#define CANAL_G 1 /* Constante usada para se referir ao canal verde. */
#define CANAL_B 2 /* Constante usada para se referir ao canal azul. */

typedef struct
{
	unsigned long largura;
	unsigned long altura;
	unsigned short n_canais; /* N�mero de canais (1 - monocrom�tica, 3 - RGB). */
	unsigned char*** dados; /* Matrizes de dados. Imagens monocrom�ticas t�m somente uma matriz, imagens coloridas t�m 3. */
} Imagem;

/*============================================================================*/

Imagem* criaImagem (int largura, int altura, int n_canais);
void destroiImagem (Imagem* img);
Imagem* abreImagem (const char* arquivo);
int salvaImagem (Imagem* img, const char* arquivo);

/*============================================================================*/
#endif /* __IMAGEM_H */
