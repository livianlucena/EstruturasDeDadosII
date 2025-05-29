#include <stdio.h>
#include <time.h>
#include <locale.h>

int x(int n);

int main() {
    int n = 10000;  
    int N_Max = 1000;
    double tempo_total = 0;

    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();
        x(n);
        clock_t end = clock();
        tempo_total += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio: %f segundos. \n", tempo_total / N_Max);
    return 0;
}

int x(int n) {
    if (n <= 1) return 1;

    int anterior = 1;
    int atual = 1;
    int proximo;

    for (int i = 2; i <= n; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    return atual;
}