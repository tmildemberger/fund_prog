#include <stdio.h>

int main() {
    int dia_nasc, mes_nasc, ano_nasc;
    int dia_atual, mes_atual, ano_atual;
    printf("Escreva uma data de nascimento (formato dd/MM/yyyy): ");
    scanf("%d/%d/%d", &dia_nasc, &mes_nasc, &ano_nasc);
    printf("Escreva uma data atual (formato dd/MM/yyyy): ");
    scanf("%d/%d/%d", &dia_atual, &mes_atual, &ano_atual);
    int idade;
    idade = ano_atual - ano_nasc;
    if (mes_atual < mes_nasc || (mes_atual == mes_nasc && dia_atual < dia_nasc)) {
        --idade;
    }
    printf("Essa pessoa tem %d anos\n", idade);
    if (idade < 0) {
        printf("Voce nao faz sentido\n");
    } else if (idade < 18) {
        printf("Menor de idade\n");
    } else {
        printf("Maior de idade\n");
    }
    return 0;
}
