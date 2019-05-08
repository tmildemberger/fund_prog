#include <stdio.h>

void intercala(const char *str1, const char * str2);

int main() {
    intercala("Em de espeto   de", "casa   ferreiro e pau");
    return 0;
}

void intercala(const char *str1, const char * str2) {
    while (*str1 || *str2) {
        while (*str1) {
            if (*str1 == ' ') {
                while (*(++str1) == ' ');
                break;
            }
            printf("%c", *(str1)++);
        }
        printf(" ");
        while (*str2) {
            if (*str2 == ' ') {
                while (*(++str2) == ' ');
                break;
            }
            printf("%c", *(str2)++);
        }
        printf(" ");
    }
    printf("\n");
}
