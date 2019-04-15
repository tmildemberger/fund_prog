#include <stdio.h>

float potencia(float a, int b);

int main() {
    int i, j;
    for (i=2;i<=10;i++) {
      for (j=0; j<=10;j++) {
        printf("%d^%d=%.0f ",i,j, potencia(i,j) );
      }
      printf("\n");
    }
    return 0;
}

float potencia(float a, int b) {
    float c = 1;
    for (;b>0;b--) c*=a;
    return c;
}
