int printf(const char*, ...);

void upper(char *str);

int main() {
    char kk[] = "ola mundo KKJ";
    upper(kk);
    printf("%s\n", kk);
    return 0;
}

void upper(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str += 'A' - 'a';
        }
        str++;
    }
}
