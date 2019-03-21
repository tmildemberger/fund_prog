#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n1 = rand() % 100 + 1;
    int n2 = rand() % 100 + 1;
    int operacao = rand() % 4;
    int resultado;
    char op_ch;
    if (operacao == 0) {
        op_ch = '+';
        resultado = n1 + n2;
    } else if (operacao == 1) {
        op_ch = '-';
        resultado = n1 - n2;
    } else if (operacao == 2) {
        op_ch = '*';
        resultado = n1 * n2;
    } else if (operacao == 3) {
        op_ch = '/';
        resultado = n1 / n2;
    }
    printf("Faca a operacao %d %c %d: ", n1, op_ch, n2);
    clock_t inicio = clock();
    int resposta;
    scanf("%d", &resposta);
    clock_t fim = clock();
    if (resposta == resultado) {
        printf("Acertou! ");
    } else {
        printf("Ahh! Errou. ");
    }
    printf("Seu tempo foi %.3f s\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    return 0;
}