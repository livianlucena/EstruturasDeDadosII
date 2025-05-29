#include <stdio.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int x(int n);

int main() {
    int n = 5000;  
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
    double raiz5 = sqrt(5.0);
    double phi = (1 + raiz5) / 2;
    double psi = (1 - raiz5) / 2;

    double resultado = (pow(phi, n) - pow(psi, n)) / raiz5;
    return (int)(resultado + 0.5);  
}