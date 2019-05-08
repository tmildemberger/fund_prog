#include <stdio.h>
#include <string.h>

#define N 16

void concatenaN(char *str1, const char *str2, int n);

int main() {
    char mel[N] = "melancia";
    concatenaN(mel, "jabuticaba", N - strlen(mel) - 1);
    printf("%s\n", mel);
    return 0;
}

void concatenaN(char *str1, const char *str2, int n) {
    str1 += strlen(str1);
    int i;
    for (i = 0; i < n; ++i) {
        *str1++ = *str2++;
    }
    *str1 = '\0';
}
