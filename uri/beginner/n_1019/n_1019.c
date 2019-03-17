#include <stdio.h>

int main() {
    int seconds;
    scanf("%d", &seconds);
    printf("%d:", seconds / (60 * 60));
    seconds %= (60 * 60);
    printf("%d:", seconds / 60);
    seconds %= 60;
    printf("%d\n", seconds);
    return 0;
}