#include <stdio.h>
#include <string.h>



int main() {
    char str[50];

    do {
        fgets(str,50,stdin);
        str[strlen(str) - 1] = '\0';
        printf("%ld\n", strlen(str));

    } while (strcmp(str, "FIM"));
    return 0;
}
