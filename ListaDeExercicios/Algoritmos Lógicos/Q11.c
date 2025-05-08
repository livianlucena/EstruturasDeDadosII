/*
Busca Binária
Implemente busca binária em um vetor ordenado.
*/

#include <stdio.h>
#include <locale.h>

// Função de busca binária
int buscaBinaria(int arr[], int n, int chave) {
    int inicio = 0;
    int fim = n - 1;

    // Enquanto a sublista não for vazia
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        // Se a chave for encontrada no meio
        if (arr[meio] == chave) {
            return meio;  // Retorna o índice do elemento encontrado
        }
        // Se a chave for menor que o elemento do meio, procura à esquerda
        else if (arr[meio] > chave) {
            fim = meio - 1;
        }
        // Se a chave for maior que o elemento do meio, procura à direita
        else {
            inicio = meio + 1;
        }
    }

    // Se o valor não foi encontrado, retorna -1
    return -1;
}

int main() {
    // Vetor ordenado para busca
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calcula o tamanho do vetor
    int chave;

    setlocale(LC_ALL, "portuguese");  

    // Solicita ao usuário o número a ser buscado
    printf("Digite o número a ser buscado: ");
    scanf("%d", &chave);

    // Chama a função de busca binária
    int resultado = buscaBinaria(arr, n, chave);

    // Verifica se o número foi encontrado
    if (resultado != -1) {
        printf("O número %d foi encontrado na posição %d.\n", chave, resultado);
    } else {
        printf("O número %d não foi encontrado no vetor.\n", chave);
    }

    return 0;
}
