/*
Verificador de Palíndromo
Dada uma string (array de char), diga se ela é um palíndromo (ex: “arara”, “radar”).
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

// Função que verifica se a string é um palíndromo
int verificarPalindromo(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        // Ignorar espaços à esquerda e à direita
        if (str[inicio] == ' ') {
            inicio++;
        } else if (str[fim] == ' ') {
            fim--;
        } else {
            // Comparar os caracteres ignorando maiúsculas/minúsculas
            char charInicio = str[inicio];
            char charFim = str[fim];

            // Convertendo para minúsculas manualmente
            if (charInicio >= 'A' && charInicio <= 'Z') {
                charInicio = charInicio + ('a' - 'A');
            }
            if (charFim >= 'A' && charFim <= 'Z') {
                charFim = charFim + ('a' - 'A');
            }

            // Se os caracteres não forem iguais, não é palíndromo
            if (charInicio != charFim) {
                return 0;  // Não é palíndromo
            }

            // Avança para os próximos caracteres
            inicio++;
            fim--;
        }
    }

    return 1;  // É palíndromo
}

int main() {
    char str[100];

    setlocale(LC_ALL, "portuguese");  

    // Solicita a entrada da string
    printf("Digite uma palavra ou frase para verificar se é um palíndromo: ");
    fgets(str, sizeof(str), stdin);  // Lê a string com espaços

    // Remove a quebra de linha, se presente
    str[strcspn(str, "\n")] = 0;

    // Chama a função que verifica o palíndromo
    if (verificarPalindromo(str)) {
        printf("A palavra '%s' é um palíndromo.\n", str);
    } else {
        printf("A palavra '%s' não é um palíndromo.\n", str);
    }

    return 0;
}
