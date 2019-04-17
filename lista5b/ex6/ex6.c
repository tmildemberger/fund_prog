#include <stdio.h>

int divideTotalmente(int num, int div);
int ehRegular(int num);

int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", ehRegular(num));
    return 0;
}

int divideTotalmente(int num, int div) {
    while (num % div == 0) {
        num /= div;
    }
    return num;
}

int ehRegular(int num) {
    num = divideTotalmente(num, 2);
    if (num == 1) return 1;
    num = divideTotalmente(num, 3);
    if (num == 1) return 1;
    num = divideTotalmente(num, 5);
    return num == 1;
}
