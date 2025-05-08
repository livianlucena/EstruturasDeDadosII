/*
Soma Diagonal Principal
Crie uma matriz 4x4 e calcule a soma da diagonal principal.
*/

#include <stdio.h>
#include <locale.h>

int main() {
    int matriz[4][4];
    int somaDiagonal = 0;

    setlocale(LC_ALL, "Portuguese");

    // Leitura da matriz 4x4
    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            // Soma da diagonal principal
            if (i == j) {
                somaDiagonal += matriz[i][j];
            }
        }
    }

    // Exibe a matriz
    printf("\nMatriz informada:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    // Exibe a soma da diagonal principal
    printf("\nSoma da diagonal principal: %d\n", somaDiagonal);

    return 0;
}
