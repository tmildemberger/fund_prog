#include <stdio.h>

void imprimeTabuada(int num);

int main() {
    int num;
    scanf("%d", &num);
    imprimeTabuada(num);
    return 0;
}

void imprimeTabuada(int num) {
    int i;
    for (i = 1; i <= 10; ++i) {
        printf("%d\n", num * i);
    }
}