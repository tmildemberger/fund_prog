#include <stdio.h>

void CebolinhaString(char *dest, const char *src);

int main() {
    char dest[50];
    CebolinhaString(dest, "O RATOR RROEU A ROUPA DO REI DE ROMAR");
    printf("%s\n", dest);
    return 0;
}

void CebolinhaString(char *dest, const char *src){
    while (*src) {
        if (*src == 'R' && *(src + 1) != ' ' && *(src + 1) != '\0' ) {
            if (*(src + 1) != 'R') *(dest++) = 'L';
            else {
                *(dest++) = 'L';
                src++;
            }
        }
        else *(dest++) = *src;
        src++;
    }
    *dest = '\0';
}
