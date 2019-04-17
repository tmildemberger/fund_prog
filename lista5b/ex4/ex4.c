#include <stdio.h>
int verifica(int n1, int n2);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", verifica(a, b));
    return 0;
}

int verifica(int n1, int n2) {
    if (n2 > n1) return 0;
    while (n2 != 0 && n1 % 10 == n2 % 10) {
        n1 /= 10;
        n2 /= 10;
    }
    return n2 == 0;
}
