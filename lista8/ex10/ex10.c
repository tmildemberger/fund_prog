#include <stdio.h>
#include <string.h>

void getSubString(char *dest, char *src, int begin, int end);

int main() {
    char src[50], dest[50];
    fgets(src, 50, stdin);
    int b,e;
    scanf("%d %d", &b, &e);

    getSubString(dest, src, b, e);
    printf("%s\n", dest);
    return 0;
}

void getSubString(char *dest, char *src, int begin, int end) {
    char* max = src + end;
    src += begin;
    while (src <= max) {
        *(dest++) = *(src++);
    }
    *dest = '\0';
}
