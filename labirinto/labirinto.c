#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct coordenada {
    int x;
    int y;
} Coordenada;

int** alocaMatriz(int nl, int nc);
void imprimeMatriz(int **m, int tam);
void desalocaMatriz(int **mat, int nl);
void imprimeCriativ(int **m, int nl, int nc, Coordenada *c, int tamc); //a ser implementada na fase das tarefas
void inicializaLabirinto(int **m, int tam, Coordenada cRato, Coordenada cQueijo);
void preencheMatrizCusto(int **m, int tam, int xQueijo, int yQueijo);
Coordenada* calculaCaminho (int **m, int tam, int xRato, int yRato, int *nroPassos);
int testaCoordenadas(Coordenada c, int tam, const char alvo[]); //a ser implementada na fase dos desafios
int testaCoordenadas2(Coordenada *c, int tam, const char alvo[]); //a ser implementada na fase dos desafios

int main() {
    srand(time(NULL));
    int **lab,
        tam,     //tamanho fixo para fase de testes
        nPassos; //vai armazenar o tamanho do caminho c

    Coordenada *c,      //armazena as coordenadas do caminho
               cRato,   //coordenadas do Rato
               cQueijo; //coordenadas do Queijo

    // tam = 10;
    printf("Tamanho do labirinto: ");
    scanf("%d", &tam);

    do {
        // cQueijo.x = 5;
        // cQueijo.y = 2;
        printf("Coordenadas do queijinho: ");
        scanf("%d %d", &cQueijo.x, &cQueijo.y);
    } while (testaCoordenadas2(&cQueijo, tam, "queijo") != 1);

    do {
        // cRato.x = 8;
        // cRato.y = 8;
        printf("Coordenadas do ratinho: ");
        scanf("%d %d", &cRato.x, &cRato.y);
    } while (testaCoordenadas(cRato, tam, "rato") != 1);

    lab = alocaMatriz(tam, tam);                    //aloca labirinto
    inicializaLabirinto(lab, tam, cRato, cQueijo);  //inicializa com configuração padrão

    imprimeMatriz(lab, tam);
    preencheMatrizCusto(lab, tam, cQueijo.x, cQueijo.y);
                //preenche a matriz de custo, considerando a
                //(5,2) como localização do queijo - configuração fixa
                // para facilitar os testes

    imprimeMatriz(lab, tam);

    c = calculaCaminho(lab, tam, cRato.x, cRato.y, &nPassos); 
                // preenche c com coordenadas do caminho entre as coordenadas
                // do rato (8,8). Depois, alterar de tal forma
                // a ler do teclado.

    //imprimir caminho de forma criativa
    imprimeCriativ(lab, tam, tam, c, nPassos);

    desalocaMatriz(lab, tam);
    free(c);
    return 0;
}

int** alocaMatriz(int nl, int nc) {
    int **m, i;

    m = (int**) malloc(sizeof (int*) * nl);

    for (i = 0; i < nl; ++i)
        m[i] = (int*) malloc(sizeof (int) * nc);

    return m;
}

void desalocaMatriz(int **mat, int nl) {
    int i;
    for (i = 0; i < nl; ++i) free(mat[i]);
    free(mat);
}

void imprimeMatriz(int **m, int tam) {
    int i, j;

    for (i = 0; i < tam; ++i){
        for (j = 0; j < tam; ++j)
            printf("%4d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

void inicializaLabirinto(int **m, int tam, Coordenada cRato, Coordenada cQueijo) {
    int i, j;

    for (i = 0; i < tam; ++i)
        for (j = 0; j < tam; ++j)
            m[i][j] = -1;

    for (i = 0; i < tam * tam / 10; ++i) {
        int x = rand() % (tam - 2) + 1;
        int y = rand() % (tam - 2) + 1;
        if ((x == cRato.x   && y == cRato.y) ||
            (x == cQueijo.x && y == cQueijo.y)) --i;
        else if (m[x][y] == -1) m[x][y] = -2;
        else --i;
    }
}


void preencheMatrizCusto(int **m, int tam, int xQueijo, int yQueijo) {

    int i, j,
        dist = 0,
        deNovo = 1;

    m[xQueijo][yQueijo] = 0;
    while (deNovo == 1) {
        deNovo = 0;
        for (i = 1; i < tam - 1; ++i) {
            for (j = 1; j < tam - 1; ++j) {
                if (m[i][j] == dist) {
                    if (m[i-1][j] == -1)
                        m[i-1][j] = dist + 1;
                    if (m[i+1][j] == -1)
                        m[i+1][j] = dist + 1;
                    if (m[i][j-1] == -1)
                        m[i][j-1] = dist + 1;
                    if (m[i][j+1] == -1)
                        m[i][j+1] = dist + 1;
                    deNovo = 1;
                }
            }
        }
        ++dist;
    }
}



Coordenada* calculaCaminho (int **m, int tam, int xRato, int yRato, int *nroPassos) {
    *nroPassos = m[xRato][yRato] + 1;
    Coordenada* caminho = (Coordenada*) malloc(sizeof (Coordenada) * (*nroPassos));

    caminho[0].x = xRato;
    caminho[0].y = yRato;

    int i;
    for (i = 1; i < *nroPassos; ++i) {
        int anterior = m[caminho[i-1].x][caminho[i-1].y];
        int xAnt = caminho[i-1].x;
        int yAnt = caminho[i-1].y;

        int offset;
        int encontrou = 0;
        for (offset = -1; offset <= 1; offset += 2) {
            if (m[xAnt + offset][yAnt] == anterior - 1) {
                caminho[i].x = xAnt + offset;
                caminho[i].y = yAnt;
                encontrou = 1;
                break;
            }
            else if (m[xAnt][yAnt + offset] == anterior - 1) {
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
    int i, j, k;
    for (i = 0; i < nl; ++i) {

        for (j = 0; j < nc; ++j) {
            // bordas do labirinto (são paredes por enquanto)
            if (i == 0 || j == 0 || i == nl - 1 || j == nc - 1) {
                printf("\U0001F9F1"); // paredinha
                continue;
            }

            if ( i == c[tamc - 1].x && j == c[tamc - 1].y) printf("\U0001F9C0"); // queijinho
            else if ( i == c[0].x && j == c[0].y) printf("\U0001F401");          // ratinho
            else {
                int desenhou = 0;
                for (k = 1; k < tamc - 1; ++k) {
                    if ( i == c[k].x && j == c[k].y) {
                        printf("\U0001F463"); // pegadinhas
                        desenhou = 1;
                    }

                }
                if (!desenhou) {
                    if (m[i][j] == -2) printf("\U0001F9F1"); // paredinha
                    else printf("\U00003000");               // espaçinho
                }
            }
        }
        printf("\n");
    }
}

int testaCoordenadas(Coordenada c, int tam, const char alvo[]) {
    if (c.x <= 0 || c.x > tam - 1 ||
        c.y <= 0 || c.y > tam - 1) {
        printf("Coordenada invalida para %s\n", alvo);
        return -1;
    } else return 1;
}

int testaCoordenadas2(Coordenada *c, int tam, const char alvo[]) {
    if (c->x <= 0 || c->x >= tam - 1 ||
        c->y <= 0 || c->y >= tam - 1) {
        printf("Coordenada invalida para %s\n", alvo);
        return -1;
    } else return 1;
}