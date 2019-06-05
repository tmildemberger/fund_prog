#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 1024

char* empactoaString(char* string);

int main() {

    char buffer[BUFLEN];
    fgets (buffer, BUFLEN, stdin);

    char* empacc = empactoaString(buffer);

    printf("%s\n", empacc);
    free(empacc);

    return 0;
}

char* empactoaString(char* string) {
    char *c = (char*) malloc(sizeof(char)*(strlen(string)+1));
    strcpy(c, string);
    return c;

}
