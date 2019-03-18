#include <stdio.h>

int main() {
    float x, y;
    printf("digite as coordenadas de um ponto:");
    scanf("%f %f", &x, &y);

    if (x == 0 && y == 0) printf("Origem\n");
    else if (x == 0) printf("Eixo y\n");
    else if (y == 0) printf("Eixo x\n");
    else if (x > 0) {
      if (y > 0) printf("Q1\n");
      else printf("Q4\n");
    }
    else {
      if (y > 0) printf("Q2\n");
      else printf("Q3\n");
    }


    return 0;
}
