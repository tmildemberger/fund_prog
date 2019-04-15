#include <stdio.h>

int ehBissexto(int ano);

int main() {
    int ano;
    scanf("%d", &ano);
    printf("%d\n", ehBissexto(ano));
    return 0;
}

int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}
