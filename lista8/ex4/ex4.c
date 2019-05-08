#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "ANA", str2[] = "ANA E MARIANA GOSTAM DE BANANA";
    int nVezes = 0, aparece, i, j;
    for (i = 0; i < strlen(str2)-strlen(str1)+1; i++) {
        aparece = 1;
        for(j=0; j < strlen(str1); j++) {
            if (str1[j] != str2[i + j]) {
                aparece = 0;
                break;
            }
        }
        if (aparece) nVezes++;
    }
    printf("%d\n", nVezes);
}
