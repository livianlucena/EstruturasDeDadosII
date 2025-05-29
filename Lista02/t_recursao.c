#include <stdio.h>    
#include <time.h>     // Para medir tempo com clock()
#include <stdlib.h>   
#include <locale.h>   

// Função que calcula o n-ésimo número de Fibonacci 
int x(int n, int memo[]);

int main() {
    int n = 1000;             // Termo da sequência de Fibonacci que será calculado
    int N_Max = 1000;         // Número de execuções para calcular tempo médio
    double tempo_total = 0;   // Acumulador do tempo total

    // Loop para medir o tempo de execução repetido N_Max vezes
    for (int i = 0; i < N_Max; i++) {
        // Aloca dinamicamente o vetor memo com n+1 posições
        int* memo = (int*)malloc((n + 1) * sizeof(int));

        // Inicializa o vetor memo com -1 indicando que os termos ainda não foram calculados
        for (int j = 0; j <= n; j++) {
            memo[j] = -1;
        }

        // Marca o tempo de início
        clock_t start = clock();

        // Chama a função Fibonacci com memoização
        x(n, memo);

        // Marca o tempo de término
        clock_t end = clock();

        // Soma o tempo decorrido nesta execução ao total
        tempo_total += (double)(end - start) / CLOCKS_PER_SEC;

        // Libera a memória alocada para o vetor memo
        free(memo);
    }

    // Exibe o tempo médio por execução
    printf("Tempo médio: %f segundos.\n", tempo_total / N_Max);

    return 0; // Encerra o programa
}

// Função recursiva com memoização para calcular Fibonacci(n)
int x(int n, int memo[]) {
    // Casos base: F(0) = 1, F(1) = 1
    if (n <= 1) return 1;

    // Se já foi calculado, retorna o valor armazenado
    if (memo[n] != -1) {
        return memo[n];
    }

    // Calcula e armazena o valor para evitar chamadas futuras
    memo[n] = x(n - 1, memo) + x(n - 2, memo);
    return memo[n];
}
