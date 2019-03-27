#include <stdio.h>

int main() {
    int numero, m = 0;
    scanf("%d", &numero); //considerando numero >= 2
    while (2 + numero * m <= 10000) {
        printf("%d\n", 2 + numero * m++);
    }
    return 0;
}
