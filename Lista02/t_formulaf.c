#include <stdio.h>    
#include <time.h>     // Para medir tempo de execução
#include <math.h>     
#include <locale.h>   

// Função que calcula o n-ésimo termo da sequência de Fibonacci 
int x(int n);

int main() {
    int n = 5000;           // Termo da sequência de Fibonacci que será calculado
    int N_Max = 1000;       // Número de vezes que o cálculo será repetido para obter tempo médio
    double tempo_total = 0; // Variável acumuladora do tempo total gasto

    // Loop que repete o cálculo N_Max vezes para obter o tempo médio
    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();   // Captura o tempo inicial
        x(n);                      // Executa a função de Fibonacci
        clock_t end = clock();     // Captura o tempo após execução

        // Adiciona o tempo decorrido ao acumulador
        tempo_total += (double)(end - start) / CLOCKS_PER_SEC;
    }

    // Imprime o tempo médio de execução por chamada
    printf("Tempo médio: %f segundos.\n", tempo_total / N_Max);

    return 0; // Fim do programa
}

// Função que calcula o n-ésimo número de Fibonacci 
int x(int n) {
    double raiz5 = sqrt(5.0);             // Calcula raiz quadrada de 5
    double phi = (1 + raiz5) / 2;         // Número de ouro (aproximadamente 1.618)
    double psi = (1 - raiz5) / 2;         // Conjugado de phi (aproximadamente -0.618)

    // Aplica a fórmula de Binet: F(n) = (phi^n - psi^n) / sqrt(5)
    double resultado = (pow(phi, n) - pow(psi, n)) / raiz5;

    // Arredonda o resultado para o inteiro mais próximo e retorna
    return (int)(resultado + 0.5);
}
