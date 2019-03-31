#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <string.h>

int main() {
    long long int quantos_primos;
    long long int inicial;
    scanf("%lld %lld", &quantos_primos, &inicial);
    if (quantos_primos <= 0 || inicial <= 0) {
        printf("os numeros devem ser positivos (0 nao e positivo)\n");
        return 1;
    }
    if (inicial == 1) ++inicial; //pois um nao e primo
    long long int encontrados = 0;
    long long int inicial_real = inicial;
    // printf("********************\nTestando algoritmo lento:\n");
    // clock_t inicio_lento = clock();
    // while (encontrados < quantos_primos) {
    //     long long int divisor;
    //     int e_primo = 1;
    //     for (divisor = 2; divisor < inicial; ++divisor) {
    //         if (inicial % divisor == 0) {
    //             e_primo = 0;
    //             break;
    //         }
    //     }
    //     if (e_primo) {
    //         ++encontrados;
    //         printf("%lld eh primo\n", inicial);
    //     }
    //     ++inicial;
    // }
    // clock_t fim_lento = clock();
    // encontrados = 0;
    // inicial = inicial_real;
    // printf("********************\nTestando algoritmo menos lento:\n");
    // clock_t inicio_ok = clock();
    // while (encontrados < quantos_primos) {
    //     long long int divisor;
    //     int e_primo = 1;
    //     for (divisor = 2; divisor < inicial / 2; ++divisor) {
    //         if (inicial % divisor == 0) {
    //             e_primo = 0;
    //             break;
    //         }
    //     }
    //     if (e_primo) {
    //         ++encontrados;
    //         printf("%lld eh primo\n", inicial);
    //     }
    //     ++inicial;
    // }
    // clock_t fim_ok = clock();
    // encontrados = 0;
    // inicial = inicial_real;
    printf("********************\nTestando algoritmo rapido:\n");
    clock_t inicio_melhor = clock();
    while (encontrados < quantos_primos) {
        long long int divisor = 2;
        int e_primo = 1;
        if (inicial % 2 == 0) {
            if (inicial == 2) {
                ++encontrados;
                printf("2 eh primo\n");
            }
            ++inicial;
            continue;
        }
        for (divisor = 3; divisor <= round(sqrt(inicial)); divisor += 2) {
            if (inicial % divisor == 0) {
                e_primo = 0;
                break;
            }
        }
        if (e_primo) {
            ++encontrados;
            printf("%lld eh primo\n", inicial);
        }
        inicial += 2;
    }
    clock_t fim_melhor = clock();
    encontrados = 0;
    inicial = inicial_real;
    printf("********************\nTestando algoritmo muito rapido:\n");
    clock_t inicio_etapa = clock();
    // {
    //     int procurado = 3;
    //     printf("procurando %d ate %d\n", procurado, (int)round(sqrt(round(sqrt(LONG_LONG_MAX)))));
    //     while (procurado <= round(sqrt(round(sqrt(LONG_LONG_MAX))))) {
    //         long long int divisor;
    //         int e_primo = 1;
    //         for (divisor = 3; divisor <= round(sqrt(procurado)); divisor += 2) {
    //             if (procurado % divisor == 0) {
    //                 e_primo = 0;
    //                 break;
    //             }
    //         }
    //         if (e_primo) {
    //             ++encontrados;
    //         }
    //         procurado += 2;
    //     }
    // }
    // long long int primeiros_primos[encontrados + 2];
    // primeiros_primos[0] = 2;
    // primeiros_primos[encontrados + 1] = LONG_LONG_MAX;
    // encontrados = 0;
    // {
    //     int procurado = 3;
    //     while (procurado <= round(sqrt(round(sqrt(LONG_LONG_MAX))))) {
    //         long long int divisor;
    //         int e_primo = 1;
    //         for (divisor = 3; divisor <= round(sqrt(procurado)); divisor += 2) {
    //             if (procurado % divisor == 0) {
    //                 e_primo = 0;
    //                 break;
    //             }
    //         }
    //         if (e_primo) {
    //             ++encontrados;
    //             primeiros_primos[encontrados] = procurado;
    //         }
    //         procurado += 2;
    //     }
    // }
    // printf("acabei de preencher um vetor com os %d primeiros primos\n", encontrados);
    const int vezes_totais = 1600;
    long long int *primos_todos_real = calloc(vezes_totais * 128 * 1024 + 1, sizeof (long long int));
    primos_todos_real[0] = 3;
    long long int *primos_todos = primos_todos_real + 1;
    long long int ultimo = 0;
    FILE *raw;
    raw = fopen("raw_primes", "rb");
    long long int raw_read = 0;
    if (raw) {
        raw_read = fread(primos_todos, sizeof (long long int), vezes_totais * 128 * 1024, raw);
    }
    if (raw_read == vezes_totais * 128 * 1024) {
        printf("raw lido com sucesso\n");
        ultimo = vezes_totais * 128 * 1024;
    } else {

        FILE *primes;
        primes = fopen("primes", "r");
        if (!primes) {

            primes = fopen("primes", "w");
            FILE *primes_temp = fopen("primes_temp", "w");
            int vezes;
            for (vezes = 0; vezes < vezes_totais; ++vezes) {
                encontrados = 0;
                long long int primos[128 * 1024];
                {
                    long long int procurado = primos_todos[ultimo - 1];
                    printf("procurando %lld ate encontrar %d\n", procurado, 128 * 1024);
                    while (encontrados < 128 * 1024) {
                        long long int divisor;
                        int e_primo = 1;
                        long long int idx = 0;
                        for (divisor = primos_todos[idx]; divisor <= round(sqrt(procurado)) && idx < ultimo; divisor = primos_todos[++idx]) {
                            if (procurado % divisor == 0) {
                                e_primo = 0;
                                break;
                            }
                        }
                        for (divisor = primos_todos[ultimo - 1]; divisor <= round(sqrt(procurado)); divisor += 2) {
                            if (procurado % divisor == 0) {
                                e_primo = 0;
                                break;
                            }
                        }
                        if (e_primo) {
                            primos[encontrados] = procurado;
                            ++encontrados;
                        }
                        procurado += 2;
                    }
                    memcpy(&(primos_todos[ultimo]), primos, 128 * 1024 * sizeof (long long int));
                    int i;
                    for (i = 0; i < 128 * 1024; ++i) {
                        fprintf(primes_temp, "%lld,", primos_todos[ultimo + i]);
                    }
                    fflush(primes_temp);
                    ultimo += 128 * 1024;
                }
                printf("acabei de preencher um vetor com %lld primos\n", encontrados);
            }

            int i;
            for (i = 0; i < ultimo; ++i) {
                fprintf(primes, "%lld,", primos_todos[i]);
            }
            fclose(primes);
        } else {
            int i = 0;
            while (fscanf(primes, "%lld,", &(primos_todos[i])) != EOF) {
                ++i;
                ++ultimo;
            }
            printf("acabei de preencher um vetor com os %lld primeiros primos\n", ultimo);
            fclose(primes);
            if (ultimo < vezes_totais * 128 * 1024) {
                printf("faltam %lld primos para serem calculados\n", vezes_totais * 128 * 1024 - ultimo);
                long long int comecando = ultimo;
                primes = fopen("primes", "a");
                FILE *primes_temp = fopen("primes_temp", "a");
                int vezes;
                for (vezes = ultimo / (128 * 1024); vezes < vezes_totais; ++vezes) {
                    encontrados = 0;
                    long long int primos[128 * 1024];
                    {
                        long long int procurado = primos_todos[ultimo - 1];
                        printf("procurando %lld ate encontrar %d\n", procurado, 128 * 1024);
                        while (encontrados < 128 * 1024) {
                            long long int divisor;
                            int e_primo = 1;
                            long long int idx = 0;
                            for (divisor = primos_todos[idx]; divisor <= round(sqrt(procurado)) && idx < ultimo; divisor = primos_todos[++idx]) {
                                if (procurado % divisor == 0) {
                                    e_primo = 0;
                                    break;
                                }
                            }
                            for (divisor = primos_todos[ultimo - 1]; divisor <= round(sqrt(procurado)); divisor += 2) {
                                if (procurado % divisor == 0) {
                                    e_primo = 0;
                                    break;
                                }
                            }
                            if (e_primo) {
                                primos[encontrados] = procurado;
                                ++encontrados;
                            }
                            procurado += 2;
                        }
                        memcpy(&(primos_todos[ultimo]), primos, 128 * 1024 * sizeof (long long int));
                        long long int idx;
                        for (idx = 0; idx < 128 * 1024; ++idx) {
                            fprintf(primes_temp, "%lld,", primos_todos[ultimo + idx]);
                        }
                        fflush(primes_temp);
                        ultimo += 128 * 1024;
                    }
                    printf("acabei de preencher um vetor com %lld primos\n", encontrados);
                }

                long long int idx;
                for (idx = comecando; idx < ultimo; ++idx) {
                    fprintf(primes, "%lld,", primos_todos[idx]);
                }
                fclose(primes);
            } else {
                FILE *raw_primes = fopen("raw_primes", "wb");
                long long int teste = fwrite(primos_todos, sizeof (long long int), ultimo, raw_primes);
                if (teste == ultimo) {
                    printf("movido arquivo raw com sucesso\n");
                }
                fclose(raw_primes);
            }
        }
    }
    clock_t fim_etapa = clock();
    // printf("maior primo calculado: %lld", primos_todos[ultimo]);
    // scanf("%d", &encontrados);
    // encontrados = 0;
    // {
    //     int procurado = 3;
    //     while (procurado <= round(sqrt(LONG_LONG_MAX))) {
    //         long long int divisor_i;
    //         int e_primo = 1;
    //         for (divisor_i = 0; primeiros_primos[divisor_i] <= round(sqrt(procurado)); ++divisor_i) {
    //             if (procurado % primeiros_primos[divisor_i] == 0) {
    //                 e_primo = 0;
    //                 break;
    //             }
    //         }
    //         if (e_primo) {
    //             ++encontrados;
    //             primos[encontrados] = procurado;
    //         }
    //         procurado += 2;
    //     }
    // }

    clock_t inicio_mais_melhor = clock();
    encontrados = 0;
    while (encontrados < quantos_primos) {
        long long int divisor;
        long long int idx = 0;
        int e_primo = 1;
        if (inicial % 2 == 0) {
            if (inicial == 2) {
                ++encontrados;
                printf("2 eh primo\n");
            }
            ++inicial;
            continue;
        }
        for (divisor = primos_todos[idx]; divisor <= round(sqrt(inicial)); divisor = primos_todos[++idx]) {
            if (inicial % divisor == 0) {
                e_primo = 0;
                break;
            }
        }
        if (e_primo) {
            ++encontrados;
            printf("%lld eh primo\n", inicial);
        }
        inicial += 2;
    }

    // encontrados = 0;
    // while (encontrados < quantos_primos) {
    //     long long int divisor_i;
    //     int e_primo = 1;
    //     if (inicial % 2 == 0) {
    //         if (inicial == 2) {
    //             ++encontrados;
    //             printf("2 eh primo\n");
    //         }
    //         ++inicial;
    //         continue;
    //     }
    //     for (divisor_i = 1; divisor_i <= 128 * 1024 && primos_todos[divisor_i] <= round(sqrt(inicial)); ++divisor_i) {
    //         if (inicial % primos[divisor_i] == 0) {
    //             e_primo = 0;
    //             break;
    //         }
    //     }
    //     for (divisor_i = primos_todos[128 * 1024 - 1]; divisor_i <= round(sqrt(inicial)); divisor_i += 2) {
    //         if (inicial % divisor_i == 0) {
    //             e_primo = 0;
    //             break;
    //         }
    //     }
    //     if (e_primo) {
    //         ++encontrados;
    //         printf("%lld eh primo\n", inicial);
    //     }
    //     inicial += 2;
    // }

    clock_t fim_mais_melhor = clock();
    printf("********************\nResultados:\n");
    printf("Encontrados %lld primos comecando em %lld em:\n", quantos_primos, inicial_real);
    // printf("%.3f segundos (ruim)\n", ((double)fim_lento - inicio_lento) / CLOCKS_PER_SEC);
    // printf("%.3f segundos (ok)\n", ((double)fim_ok - inicio_ok) / CLOCKS_PER_SEC);
    printf("%.3f segundos (bom)\n", ((double)fim_melhor - inicio_melhor) / CLOCKS_PER_SEC);
    printf("%.3f segundos (etapa)\n", ((double)fim_etapa - inicio_etapa) / CLOCKS_PER_SEC);
    printf("%.3f segundos (teste)\n", ((double)fim_mais_melhor - inicio_mais_melhor) / CLOCKS_PER_SEC);
    // free(primos);
    return 0;
}