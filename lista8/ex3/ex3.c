#include <stdio.h>
#include <string.h>

#define N 50

void contaVogais(char *str);

int main() {
    char str[N];
    fgets(str, N, stdin);
    str[strlen(str) - 1] = '\0';
    contaVogais(str);
    return 0;
}

void contaVogais(char *str) {
    int n_vogais[5] = { 0 }, i;
    for (i = 0; i < strlen(str); ++i) {
        switch (str[i]) {
            case 'a':
            case 'A':
                n_vogais[0]++;
                break;
            case 'e':
            case 'E':
                n_vogais[1]++;
                break;
            case 'i':
            case 'I':
                n_vogais[2]++;
                break;
            case 'o':
            case 'O':
                n_vogais[3]++;
                break;
            case 'u':
            case 'U':
                n_vogais[4]++;
                break;
        }
    }
    char vogais[] = "aeiou";
    for (i = 0; i < 5; ++i) {
        printf("%c : ", vogais[i]);
        int j;
        for (j = 0; j < n_vogais[i]; ++j) {
            printf("*");
        }
        printf(" (%d)\n", j);
    }
}
