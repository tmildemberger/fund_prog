#include <stdio.h>

int main() {
    int senha;
    scanf("%d", &senha);
    while (senha != 2002) {
      printf("Senha invalida\n");
      scanf("%d", &senha);
    }
    printf("Acesso permitido\n");
    return 0;
}
