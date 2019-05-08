#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    char *pstr1, *pstr2;
    fgets(str1, 50, stdin);
    fgets(str2, 50, stdin);
    pstr1 = str1 + strlen(str1);
    pstr2 = str2 + strlen(str2);
    int contida = 1;
    while(pstr2 >= str2) {
        if (*(pstr2--) != *(pstr1--)) contida = 0;
    }
    if (contida) printf("Contida\n");
    else printf("nao\n");
    return 0;
}
