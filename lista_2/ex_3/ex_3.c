#include <stdio.h>
#include <math.h>

int main() {
    int num0, num1;
    printf("Digite dois inteiros: ");
    scanf("%d %d", &num0, &num1);
    printf("%d eh o maior\n", ( num0 + num1 + abs(num0 - num1) ) / 2 );
    return 0;
}