#include <stdio.h>    
#include <time.h>     // Biblioteca para medir tempo de execução com clock()
#include <locale.h>   

// Declaração da função recursiva que calcula o n-ésimo termo da sequência de Fibonacci
int x(int);

int main() {
    int n = 40;              // Termo da sequência de Fibonacci que será calculado
    int N_Max = 1000;        // Número de vezes que o cálculo será repetido para medir o tempo médio
    double tempo_total = 0;  // Acumulador do tempo total das execuções

    // Loop para repetir o cálculo N_Max vezes
    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();    // Marca o tempo de início
        x(n);                       // Executa a função recursiva de Fibonacci
        clock_t end = clock();      // Marca o tempo de término

        // Calcula o tempo gasto nessa execução e soma ao total
        tempo_total += (double)(end - start) / CLOCKS_PER_SEC;
    }

    // Exibe o tempo médio por chamada da função x(n)
    printf("Tempo médio: %f segundos.\n", tempo_total / N_Max);

    return 0;  // Fim do programa
}

// Função recursiva que calcula o n-ésimo número da sequência de Fibonacci
int x(int n) {
    if (n <= 1) {
        return 1;  // Casos base: x(0) = 1, x(1) = 1
    } else {
        return x(n - 1) + x(n - 2);  // Fórmula recursiva: x(n) = x(n-1) + x(n-2)
    }
}
