#include <stdio.h>
#include <time.h>

int main() {
    int quantos;
    scanf("%d", &quantos);
    printf("-------\n");

    // printf("Iniciando metodo rudimentar inicial meu\n");
    clock_t inicio_ruim = clock();
    int multiplo = 1, i;
    for (i = 1; i <= quantos; ++i) {
        multiplo *= i;
        int menor_ok = multiplo;
        while (multiplo >= quantos) {
            int ok = 1, j;
            for (j = 1; j <= i; ++j) {
                if (multiplo % j != 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                menor_ok = multiplo;
            }
            --multiplo;
        }
        multiplo = menor_ok;
    }
    clock_t fim_ruim = clock();
    // printf("Fim metodo 1\n");
    // printf("Inicio metodo mais rapido\n");
    clock_t inicio_bom = clock();
    int resultado = 1;
    for (i = 2; i <= quantos; ++i) {
        if (resultado % i != 0) {
            int j;
            for (j = 2; j <= i; ++j) {
                if ((resultado * j) % i == 0) {
                    resultado *= j;
                    break;
                }
            }
        }
        printf("%d\n", resultado);
    }
    clock_t fim_bom = clock();
    // printf("Fim metodo 2\n");

    // printf("Inicio metodo do gabarito\n");
    clock_t inicio_gabarito = clock();
    int num = 0, // valor que sera testado - altera a cada iteração
        ind = 0; // variavel indicadora
        //i; // contador do for
    //a solução abaixo não é a mais eficiente possível, pois testa mais valores do que o necessário!
    while(ind == 0){ // laço indeterminado que depende da variavel indicadora

        num++; // atualiza o valor de num

        ind = 1; // inicializa com status 1
        for(i=1; i<=quantos; i++){
            if(num%i != 0){ // se encontrar algum divisor no intervalo
                ind = 0; // atualiza o status
                break; // sai do for e testa o próximo num
            }
        }
    }
    clock_t fim_gabarito = clock();
    // printf("Fim metodo 3\n");
    printf("********************\nResultados:\n");
    printf("Metodo_velho (%.3f s): %d e o menor numero divisivel por todos os numeros entre 1 e %d\n", ((double)fim_ruim - inicio_ruim) / CLOCKS_PER_SEC, multiplo, quantos);
    printf("Metodo_novo (%.3f s): %d e o menor numero divisivel por todos os numeros entre 1 e %d\n", ((double)fim_bom - inicio_bom) / CLOCKS_PER_SEC, resultado, quantos);
    printf("Metodo_gabarito (%.3f s): %d e o menor numero divisivel por todos os numeros entre 1 e %d\n", ((double)fim_gabarito - inicio_gabarito) / CLOCKS_PER_SEC, num, quantos);
    return 0;
}