#include <stdio.h>

int main() {
    int num;
    printf("Digite um inteiro no intervalo [100, 999]: ");
    scanf("%d", &num);
    if (num < 100 || num > 999) {
        printf("O numero precisa estar no intervalo\n");
    } else {
        int unidade, dezena, centena, total;
        total = num;                // no final, un^3 + dz^3 + ct^3 = num 
        unidade = num % 10;
        num /= 10;
        dezena = num % 10;
        num /= 10;
        centena = num % 10;
        unidade = unidade * unidade * unidade;
        dezena = dezena * dezena * dezena;
        centena = centena * centena * centena;
        if (unidade + dezena + centena == total) {
            printf("O numero dado e um numero de Angstron\n");
        } else {
            printf("O numero dado NAO e um numero de Angstron\n");
        }
    }
    return 0;
}