#include <stdio.h>

int main() {
  int numeros;
  scanf("%d", &numeros);
  int i, crescente = 1, decrescente = 1;
  int anterior, atual;
  scanf("%d", &anterior);
  for (i = 1; i < numeros; ++i) {
      scanf("%d", &atual);
      if (anterior >= atual) {
          crescente = 0;
      } else if (anterior <= atual) {
          decrescente = 0;
      }
      anterior = atual;
  }
  if (crescente) printf("crescente\n");
  else if (decrescente) printf("decrescente\n");
  else printf("desordenado\n");
  return 0;
}
