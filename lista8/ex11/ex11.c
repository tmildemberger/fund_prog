#include <stdio.h>
#include <string.h>

void abrevia(const char *nome);
int e_letra(char c);

int main() {
    abrevia("Paulo Jose de Almeida Prado Kkk");
    return 0;
}

void abrevia(const char *nome) {
    while (*nome) {
        if (e_letra(*nome)) {
            if (e_letra(*(nome+1)) && e_letra(*(nome+2))) {
                printf("%c.", *nome);
                while (e_letra(*++nome));
            }
            else printf("%c", *nome++);
        }
        else printf("%c", *nome++);
    }
    printf("\n");
}

int e_letra(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}
