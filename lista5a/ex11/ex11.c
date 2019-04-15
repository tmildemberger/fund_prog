#include <stdio.h>

int testaTipoChar(char c);

int main() {
    char ch;
    scanf("%c", &ch);
    printf("%c => %d\n", ch, testaTipoChar(ch));
    return 0;
}

int testaTipoChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 2;
    } else if (c >= '0' && c <= '9') {
        return 3;
    } else {
        return 0;
    }
}
