#include <stdio.h>

float aproxPi(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("Pi = %f\n", aproxPi(n));
    return 0;
}

float aproxPi(int n) {
  float piSobre4 = 0;
  int i;
  for (i = 1; i <=n; i++) {
    piSobre4 += (1. - (i%2 == 0)*2)/(2*i-1);
  }
  return piSobre4*4;
}
