#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int x(int n, int memo[]);

int main() {
    int n = 1000;  
    int N_Max = 1000;
    double tempo_total = 0;

    for (int i = 0; i < N_Max; i++) {
        int* memo = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            memo[j] = -1;  
        }

        clock_t start = clock();
        x(n, memo);
        clock_t end = clock();

        tempo_total += (double)(end - start) / CLOCKS_PER_SEC;
        free(memo);  
    }

    printf("Tempo médio: %f segundos. \n", tempo_total / N_Max);
    return 0;
}

int x(int n, int memo[]) {
    if (n <= 1) return 1;

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = x(n - 1, memo) + x(n - 2, memo);
    return memo[n];
}
