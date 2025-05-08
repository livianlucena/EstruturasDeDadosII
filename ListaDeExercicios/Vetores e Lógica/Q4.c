/*
Frequência de Números
Leia 10 números inteiros e mostre quantas vezes cada número distinto aparece.
*/

#include <stdio.h>
#include <locale.h> 


int main() {
    int numeros[10], contagem[10];  // Vetor para armazenar os números e suas contagens
    int i, j, cont, tamanho = 10;

    setlocale(LC_ALL, "portuguese");

    // Inicializa o array de contagens com 0
    for (i = 0; i < tamanho; i++) {
        contagem[i] = 0;
    }

    // Leitura dos 10 números
    printf("Informe 10 números inteiros:\n");
    for (i = 0; i < tamanho; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Verifica a frequência de cada número distinto
    for (i = 0; i < tamanho; i++) {
        // Se o número já foi contado, pula
        if (contagem[i] != 0) {
            continue;
        }

        // Conta quantas vezes o número aparece
        cont = 1;
        for (j = i + 1; j < tamanho; j++) {
            if (numeros[i] == numeros[j]) {
                cont++;
                contagem[j] = -1;  // Marca o número como já contado
            }
        }

        // Exibe o número e sua contagem
        printf("O número %d aparece %d vez(es)\n", numeros[i], cont);
    }

    return 0;
}
