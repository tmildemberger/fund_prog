#include <stdio.h>

int fibonacci01(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d <= %d \n", n, fibonacci01(n));
    return 0;
}

int fibonacci01(int n) {
  int nmenos2 = 1, nmenos1 =1, nseq = 1;
  while (nseq < n) {
    nmenos2 = nmenos1;
    nmenos1 = nseq;
    nseq = nmenos1 + nmenos2;

  }

  return nseq;
}
