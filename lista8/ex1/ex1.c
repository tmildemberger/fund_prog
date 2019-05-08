#include <stdio.h>
#include <string.h>

#define N 16

int quantasConsoantes(char *str);

int main() {
    char str[N];
    scanf("%s", str);
    printf("n_consoantes == %d\n", quantasConsoantes(str));
}

int quantasConsoantes(char *str) {
    unsigned i;
    char consoantes[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    int n_con = 0;
    for (i = 0; i < strlen(str); ++i) {
        unsigned e_consoante = 0, j;
        for (j = 0; j < strlen(consoantes); ++j) {
            if (str[i] == consoantes[j]) {
                e_consoante = 1;
                break;
            }
        }
        n_con += e_consoante;
    }
    return n_con;
}
