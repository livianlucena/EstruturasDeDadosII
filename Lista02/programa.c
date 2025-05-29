#include <stdio.h>   

// Declaração da função x 
int x(int);

int main() {
    int n = 10;  // Define a posição da sequência de Fibonacci a ser calculada

    // Chama a função x passando 10 e imprime o resultado
    printf("%d\n", x(n));

    return 0;  // Encerra o programa
}

// Função recursiva que calcula o enésimo termo da sequência de Fibonacci
int x(int n) {
    if (n <= 1) {
        return 1;  // Casos base: Fibonacci(0) = 1 e Fibonacci(1) = 1
    } else {
        // Chamada recursiva: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
        return x(n - 1) + x(n - 2);
    }
}
