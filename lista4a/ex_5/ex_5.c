#include <stdio.h>

int main() {
    int numero, soma = 0, i = 1;
    scanf("%d", &numero);
    while (i <= numero/2) {
      if (numero%i == 0) soma += i++;
      else i++;
    }
    if (soma == numero) printf("e perfeito\n");
    else printf("nao e perfeito\n");
    return 0;
}
