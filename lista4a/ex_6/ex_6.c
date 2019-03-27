#include <stdio.h>

int main() {
    float altura_chico = 1.5, altura_ze = 1.1;
    int anos = 0;
    while (altura_chico + anos * 0.02 > altura_ze + anos * 0.03) {
        ++anos;
    }
    printf("Levarao %d anos para ze ficar mais alto que chico\n", anos);
    return 0;
}
