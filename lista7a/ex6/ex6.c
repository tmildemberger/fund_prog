#include <stdio.h>

#define TAM 10

int main() {
    int vet[TAM], i = 0;
    while (i < TAM) {
        int num;
        scanf("%d", &num);
        int j, pode = 1;
        for (j = 0; j < i; ++j) {
            if (vet[j] == num) {
                printf("nao pode\n");
                pode = 0;
                break;
            }
        }
        if (pode) {
            vet[i] = num;
            ++i;
        }
    }
    return 0;
}
