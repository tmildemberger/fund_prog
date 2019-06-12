#include <stdio.h>
#include <stdlib.h>
#include "imagem.h" //Desenvolvida pelo prof. Bogdan.
#include "projetoImagens.h"
/*============================================================================*/

const char* ARQUIVOS [] = //imagens da pasta img foram geradas pelo prof. Bogdan.
{
    "img2/celula01.bmp",
    "img2/celula02.bmp",
    "img2/tulipNoise2.bmp",
    "img2/borboleta.bmp",
    "img2/lenna.bmp",
};

#define N_ARQUIVOS 5 //est� testando apenas as 3 primeiras imagens da lista
#define TAM_JANELA 5
#define DEBUG_MODE /* Setar para gravar imagens intermedi�rias. */

/******************************************************************
Fun��o principal
*******************************************************************/
int main ()
{
    int i, op, limiar;
    Imagem *img, *out; // Imagem de entrada/saida
    // char nome_saida [25]; // String usada para armazenar os nomes das sa�das

    printf("\nO que deseja fazer?\n");
    printf("1 - negativo\n");
    printf("2 - binarizacao\n");
    printf("3 - filtro da media\n");
    printf("4 - contagem de componentes conexos\n");
    scanf("%d", &op);

    if (op == 2 || op == 3) scanf("%d", &limiar);

    for (i = 0; i < N_ARQUIVOS; i++)
    {
        img = abreImagem (ARQUIVOS [i]);
        if (!img)
        {
            printf ("Nao conseguiu abrir %s\n", ARQUIVOS [i]);
            return (1);
        }
        printf ("Processando imagem %s...\n", ARQUIVOS [i]);

        switch(op)
        {
            case 1:
                out = criaImagem(img->largura, img->altura, 1);
                negativo(img, out);

                #ifdef DEBUG_MODE
                Imagem* debug = criaImagem (img->largura, img->altura, 1); //poderia salvar direto a out, mas vamos ilustrar como seria uma c�pia!
                for (unsigned int row = 0; row < img->altura; row++)
                    for (unsigned int col = 0; col < img->largura; col++)
                        debug->dados [0][row][col] = out->dados [0][row][col];
                char outFile[50];
                sprintf(outFile,"1-negative-%d.bmp", i);
                salvaImagem (debug, outFile);
                destroiImagem (debug);
                #endif
                break;
            case 2:
                out = criaImagem(img->largura, img->altura, 1);
                binariza(img, out, limiar);

                #ifdef DEBUG_MODE
                sprintf(outFile,"2-bin-%d.bmp", i); //aqui salva direto out
                salvaImagem (out, outFile);
                #endif
                break;
            case 3:
                out = criaImagem(img->largura, img->altura, 1);
                filtroMedia(img, out, limiar);

                #ifdef DEBUG_MODE
                sprintf(outFile,"3-med-%d.bmp", i); //aqui salva direto out
                salvaImagem (out, outFile);
                #endif
                break;
            case 4:
                printf("Ainda n�o implementado!!");
                return 0;
                //break;
            default:
                printf("Opcao invalida!");
        }
        destroiImagem (img);
    }


    return (0);
}
