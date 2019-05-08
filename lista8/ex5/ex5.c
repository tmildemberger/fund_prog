#include <stdio.h>
#include <string.h>

#define N 150

void cifraDeCesar(char *str, int rot);

int main() {
    char str[N];
    fgets(str, N, stdin);
    str[strlen(str) - 1] = '\0';
    cifraDeCesar(str, 1);
    printf("%s\n", str);
    return 0;
}

void cifraDeCesar(char *str, int rot) {
    int i;
    for (i = 0; i < strlen(str); ++i) {
        // if (str[i] >= 'a' && str[i] < 'z') str[i]++;
        // else if (str[i] == 'z') str[i] = 'a';
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a') + rot) % 26 + 'a';
        }
    }
}
