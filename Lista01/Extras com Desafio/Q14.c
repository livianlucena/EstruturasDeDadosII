/*
Cifra de César
Escreva uma função para criptografar uma mensagem usando a Cifra de César (deslocamento de letras).
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

// Função para aplicar a Cifra de César
void cifraCesar(char texto[], int deslocamento) {
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];

        // Para letras maiúsculas
        if (c >= 'A' && c <= 'Z') {
            texto[i] = ((c - 'A' + deslocamento) % 26) + 'A';
        }
        // Para letras minúsculas
        else if (c >= 'a' && c <= 'z') {
            texto[i] = ((c - 'a' + deslocamento) % 26) + 'a';
        }
        // Outros caracteres (espaços, pontuação) são mantidos
    }
}

int main() {
    char mensagem[200];
    int deslocamento;

    setlocale(LC_ALL, "portuguese");  


    printf("Digite a mensagem a ser criptografada: ");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remove a quebra de linha, se houver
    mensagem[strcspn(mensagem, "\n")] = '\0';

    printf("Digite o valor do deslocamento (ex: 3): ");
    scanf("%d", &deslocamento);

    cifraCesar(mensagem, deslocamento);

    printf("\nMensagem criptografada: %s\n", mensagem);

    return 0;
}
