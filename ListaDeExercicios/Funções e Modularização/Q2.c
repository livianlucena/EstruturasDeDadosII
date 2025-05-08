/*
Potência (sem usar pow)
Implemente uma função int potencia(int base, int expoente) que calcule potências usando apenas multiplicações.
*/

#include <stdio.h>
#include <locale.h>

// Função que calcula a potência de um número usando multiplicações
int potencia(int base, int expoente) {
    int produto = 1;

    // Multiplica a base por ela mesma "expoente" vezes
    for (int i = 0; i < expoente; i++) {
        produto *= base;
    }

    return produto; // Retorna o resultado final
}

int main() { 
    int base, expoente;

    setlocale(LC_ALL, "portuguese"); 

    // Entrada de dados
    printf("====== Calcular Potência ======\n\n");
    printf("Informe a base: ");
    scanf("%d", &base);
    printf("Informe o expoente: ");
    scanf("%d", &expoente);

    // Chamada da função para calcular a potência
    int produto = potencia(base, expoente);

    // Exibição do resultado
    printf("\nO valor de %d^%d = %d\n", base, expoente, produto);

    return 0; // Fim do programa
}
