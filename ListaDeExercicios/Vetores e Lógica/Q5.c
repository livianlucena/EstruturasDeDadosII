/*
Interseção de Vetores
Dado dois vetores de inteiros, mostre os elementos comuns entre eles.
*/

#include <stdio.h>
#include <locale.h> 

int main() {
    int vetor1[10], vetor2[10], interseccao[10];
    int i, j, k = 0;

    setlocale(LC_ALL, "portuguese");

    // Leitura dos dois vetores
    printf("Informe 10 elementos para o primeiro vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor1[i]);
    }

    printf("\nInforme 10 elementos para o segundo vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor2[i]);
    }

    // Encontrando a interseção dos dois vetores
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (vetor1[i] == vetor2[j]) {
                // Verifica se o número já foi adicionado à interseção
                int jaExiste = 0;
                for (int l = 0; l < k; l++) {
                    if (interseccao[l] == vetor1[i]) {
                        jaExiste = 1;
                        break;
                    }
                }

                // Se não existe na interseção, adiciona
                if (!jaExiste) {
                    interseccao[k] = vetor1[i];
                    k++;  // Incrementa a posição da interseção
                }
            }
        }
    }

    // Exibindo a interseção dos vetores
    if (k > 0) {
        printf("\nElementos comuns entre os dois vetores: ");
        for (i = 0; i < k; i++) {
            printf("%d ", interseccao[i]);
        }
    } else {
        printf("\nNão há elementos comuns entre os dois vetores.");
    }

    printf("\n");
    return 0;
}
