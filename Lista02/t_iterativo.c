#include <stdio.h>   
#include <time.h>     // Biblioteca para medir tempo com clock()
#include <locale.h>  

// Função que calcula o n-ésimo termo de Fibonacci 
int x(int n);

int main() {
    int n = 10000;           // Termo de Fibonacci que será calculado
    int N_Max = 1000;        // Número de repetições para medir tempo médio
    double tempo_total = 0;  // Acumulador para o tempo total

    // Loop para medir tempo de execução da função x() repetidamente
    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();   // Marca o tempo de início
        x(n);                      // Calcula Fibonacci(n)
        clock_t end = clock();     // Marca o tempo de término

        // Soma o tempo decorrido desta execução ao total
        tempo_total += (double)(end - start) / CLOCKS_PER_SEC;
    }

    // Imprime o tempo médio de execução
    printf("Tempo médio: %f segundos.\n", tempo_total / N_Max);

    return 0; // Finaliza o programa
}

// Função iterativa para calcular o n-ésimo número de Fibonacci
int x(int n) {
    if (n <= 1) return 1;  // Casos base: Fibonacci(0) e Fibonacci(1) = 1

    int anterior = 1;      // Fibonacci(0)
    int atual = 1;         // Fibonacci(1)
    int proximo;           // Variável auxiliar para o próximo valor

    // Loop que calcula Fibonacci até n
    for (int i = 2; i <= n; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    return atual; // Retorna o n-ésimo termo
}
