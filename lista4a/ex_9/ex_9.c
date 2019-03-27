#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int pseudoaleatorio = rand() % 500 + 1;
    int tentativas = 1;
    int chute;
    scanf("%d", &chute);
    if (chute > pseudoaleatorio) {
        printf("o chute foi alto\n");
    } else if (chute < pseudoaleatorio) {
        printf("o chute foi baixo\n");
    }
    while (chute != pseudoaleatorio) {
        scanf("%d", &chute);
        ++tentativas;
        if (chute > pseudoaleatorio) {
            printf("o chute foi alto\n");
        } else if (chute < pseudoaleatorio) {
            printf("o chute foi baixo\n");
        }
    }
    printf("acertou em %d tentativa(s)! ", tentativas);
    if (tentativas < 4) {
        printf("\\o/\n");
    } else if (tentativas < 7) {
        printf(":-D\n");
    } else if (tentativas < 11) {
        printf(":-)\n");
    } else {
        printf(":~(\n");
    }
    return 0;
}
