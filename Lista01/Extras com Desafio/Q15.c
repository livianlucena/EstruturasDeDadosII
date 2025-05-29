/*
Jogo da Forca (Console)
Desenvolva um jogo simples da forca no terminal, usando vetores e controle de fluxo.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ERROS 6
#define NUM_PALAVRAS 5

// Função para escolher uma palavra aleatória
const char* escolher_palavra() {
    static const char* palavras[NUM_PALAVRAS] = {
        "programacao", "computador", "algoritmo", "linguagem", "desenvolvimento"
    };
    srand(time(NULL));
    return palavras[rand() % NUM_PALAVRAS];
}

// Função para exibir a palavra com letras descobertas
void exibir_palavra(const char* palavra, const int* acertos) {
    for (int i = 0; i < strlen(palavra); i++) {
        if (acertos[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// Função principal do jogo
void jogar_forca() {
    const char* palavra = escolher_palavra();
    int acertos[strlen(palavra)];
    int erros = 0;
    int tentativas = 0;
    char letra;
    int venceu = 0;

    // Inicializa o vetor de acertos
    for (int i = 0; i < strlen(palavra); i++) {
        acertos[i] = 0;
    }

    printf("Bem-vindo ao Jogo da Forca!\n");
    printf("Adivinhe a palavra:\n");

    while (erros < MAX_ERROS && !venceu) {
        printf("\nTentativa %d de %d\n", tentativas + 1, MAX_ERROS);
        exibir_palavra(palavra, acertos);
        printf("Letras erradas: ");
        for (int i = 0; i < strlen(palavra); i++) {
            if (!acertos[i]) {
                printf("%c ", palavra[i]);
            }
        }
        printf("\n");

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        int acerto = 0;
        for (int i = 0; i < strlen(palavra); i++) {
            if (palavra[i] == letra && !acertos[i]) {
                acertos[i] = 1;
                acerto = 1;
            }
        }

        if (acerto) {
            printf("Boa! A letra '%c' está na palavra.\n", letra);
        } else {
            erros++;
            printf("A letra '%c' não está na palavra.\n", letra);
        }

        // Verifica se o jogador venceu
        venceu = 1;
        for (int i = 0; i < strlen(palavra); i++) {
            if (!acertos[i]) {
                venceu = 0;
                break;
            }
        }

        tentativas++;
    }

    if (venceu) {
        printf("\nParabéns! Você acertou a palavra '%s' em %d tentativas.\n", palavra, tentativas);
    } else {
        printf("\nVocê perdeu! A palavra era '%s'.\n", palavra);
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");  
    jogar_forca();
    return 0;
}
