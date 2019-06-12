#include<stdio.h>
#include<stdlib.h>

typedef struct coordenada
{
    int x;
    int y;
} Coordenada;

int** alocaMatriz(int nl, int nc);
void imprimeMatriz(int **m, int tam);
void desalocaMatriz(int** mat, int nl);
void imprimeCriativ(int **m, int nl, int nc, Coordenada *c, int tamc); //a ser implementada na fase das tarefas
void inicializaLabirinto(int **m, int tam);
void preencheMatrizCusto(int **m, int tam, int xQueijo, int yQueijo);
Coordenada* calculaCaminho (int **m, int tam, int xRato, int yRato, int *nroPassos);
//int testaCoordenadas(Coordenada c, int tam, char alvo[]);//a ser implementada na fase dos desafios

int main(){
    int **lab,
        tam, //tamanho fixo para fase de testes
        nPassos, //vai armazenar o tamanho do caminho c
        i;
    Coordenada *c, //armazena as coordenadas do caminho
    cRato, //coordenadas do Rato
    cQueijo; //coordenadas do Queijo

    tam=10;

    cQueijo.x=5;
    cQueijo.y=2;

    cRato.x=8;
    cRato.y=8;

    lab = alocaMatriz(tam, tam); //aloca labirinto
    inicializaLabirinto(lab, tam); //inicializa com configuração padrão
    imprimeMatriz(lab, tam); //imprime
    preencheMatrizCusto(lab, tam, cQueijo.x, cQueijo.y); //preenche a matriz de custo, considerando a
                                        //(5,2) como localização do queijo - configuração fixa
                                        // para facilitar os testes

    imprimeMatriz(lab, tam);

    c = calculaCaminho(lab, tam, cRato.x, cRato.y, &nPassos); // preenche c com coordenadas do caminho entre as coordenadas
                                        // do rato (8,8). Depois, alterar de tal forma
                                            // a ler do teclado.
    imprimeCriativ(lab, tam, tam, c, nPassos);

    //imprimir caminho de forma criativa
    desalocaMatriz(lab, tam);
    free(c);
    return 0;
}

int** alocaMatriz(int nl, int nc){

    int **m, i;

    m = (int**) malloc((unsigned int) nl * sizeof(int*));

    for( i = 0; i < nl; ++i)
        m[i] = (int*) malloc(nc * sizeof(int));

    return m;
}

void desalocaMatriz(int** mat, int nl) {
    int i;
    for (i = 0; i < nl; ++i) free (mat[i]);
    free(mat);
}

void imprimeMatriz(int **m, int tam){

    int i, j;

    for(i = 0; i < tam; ++i){
        for(j = 0; j < tam; ++j)
            printf("%4d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}



void inicializaLabirinto(int **m, int tam){

    int i,j;

    for(i = 0; i < tam; ++i)
        for(j = 0; j < tam; ++j){
            m[i][j] = -1;
        }



    m[2][1] = -2;
    m[2][2] = -2;
    m[2][3] = -2;
    m[3][3] = -2;
    m[3][4] = -2;
    m[4][4] = -2;
    m[5][4] = -2;
    m[6][4] = -2;
}


void preencheMatrizCusto(int **m, int tam, int xQueijo, int yQueijo){

    int i, j,
        dist = 0,
        deNovo = 1;

    m[xQueijo][yQueijo] = 0;
    while(deNovo == 1){
        deNovo = 0;
        for(i = 1; i < tam - 1; ++i){
            for(j = 1; j < tam - 1; ++j)
                if(m[i][j] == dist){
                    if(m[i-1][j] == -1)
                        m[i-1][j] = dist + 1;
                    if(m[i+1][j] == -1)
                        m[i+1][j] = dist + 1;
                    if(m[i][j-1] == -1)
                        m[i][j-1] = dist + 1;
                    if(m[i][j+1] == -1)
                        m[i][j+1] = dist + 1;
                    deNovo = 1;
                }
        }
        ++dist;
    }
}



Coordenada* calculaCaminho (int **m, int tam, int xRato, int yRato, int *nroPassos){
    *nroPassos = m[xRato][yRato] + 1;
    Coordenada* caminho = (Coordenada*) malloc(sizeof (Coordenada) * (*nroPassos));

    caminho[0].x = xRato;
    caminho[0].y = yRato;

    int i;
    for(i = 1; i < *nroPassos; ++i) {
        int anterior = m[caminho[i-1].x][caminho[i-1].y];
        int xAnt = caminho[i-1].x;
        int yAnt = caminho[i-1].y;

        int offset;
        int encontrou = 0;
        for (offset = -1; offset <= 1; offset += 2) {
            if(m[xAnt + offset][yAnt] == anterior - 1) {
                caminho[i].x = xAnt + offset;
                caminho[i].y = yAnt;
                encontrou = 1;
                break;
            }
            else if(m[xAnt][yAnt + offset] == anterior - 1) {
                caminho[i].x = xAnt;
                caminho[i].y = yAnt + offset;
                encontrou = 1;
                break;
            }
        }
        if (!encontrou) printf("moio pra ratinho\n");
    }
    return caminho;
}

void imprimeCriativ(int **m, int nl, int nc, Coordenada *c, int tamc) {
    // setlocale(LC_ALL, "en_US.utf8");
    int i, j, k;
    for (i = 0; i < nl; ++i) {

        for (j = 0; j < nc; ++j) {

            if( i == c[tamc - 1].x && j == c[tamc - 1].y) printf("\U0001F9C0");
            else if( i == c[0].x && j == c[0].y) printf("\U0001F401 ");
            else {
                int desenhou = 0;
                for (k = 1; k < tamc - 1; ++k) {
                    if( i == c[k].x && j == c[k].y) {
                        printf("\U0001F463");
                        desenhou = 1;
                    }

                }
                if (!desenhou) {
                    if (m[i][j] == -2) printf("\U0001F9F1 ");
                    else printf("\U00003000");
                }
            }
        }
        printf("\n");
    }
}
