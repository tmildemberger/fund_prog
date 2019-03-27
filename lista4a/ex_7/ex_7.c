#include <stdio.h>

int main() {
    int n, nfatorial;
    scanf("%d", &n); // para n de 0 a 12
    nfatorial = 1;
    while (n > 0) {
      nfatorial *= n--;
    }
    printf("%d\n", nfatorial);
    return 0;
}
