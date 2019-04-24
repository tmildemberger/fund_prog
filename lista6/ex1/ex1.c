#include <stdio.h>

void questao01(int *a, int *b);

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    questao01(&n1, &n2);
    printf("%d %d\n", n1, n2);
    return 0;
}

void questao01(int *a, int *b) {
    (*a)--;
    (*b)++;
}
