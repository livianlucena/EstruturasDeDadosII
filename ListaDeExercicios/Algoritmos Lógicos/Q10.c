/*
Sequência de Fibonacci Recursiva
Escreva uma função recursiva para gerar o n-ésimo número de Fibonacci.
*/

#include <stdio.h>
#include <locale.h>


// Função recursiva para calcular o n-ésimo número de Fibonacci
int fibonacci(int n) {
    if (n == 0) {
        return 0;  // Caso base: F(0) = 0
    } else if (n == 1) {
        return 1;  // Caso base: F(1) = 1
    } else {
        // Recursão: F(n) = F(n-1) + F(n-2)
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    setlocale(LC_ALL, "portuguese");  

    // Leitura do número n
    printf("Digite o valor de n para calcular o n-ésimo número de Fibonacci: ");
    scanf("%d", &n);

    // Chama a função fibonacci e exibe o resultado
    printf("O %d-ésimo número de Fibonacci é: %d\n", n, fibonacci(n));

    return 0;
}
