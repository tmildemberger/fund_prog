#include <stdio.h>

int MDC(int num1, int num2);

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("mdc(%d,%d) = %d\n", n1, n2, MDC(n1,n2));
    return 0;
}

int MDC(int num1, int num2) {

  while(num1 > 0 && num2 > 0) {
    if (num1 > num2) num1 %= num2;
    else if (num1 < num2) num2 %= num1;
    else return num1;

  }
  if (num1 == 0) return num2;
  else if (num2 == 0) return num1;
  else return 0;
}
