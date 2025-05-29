/*
Soma de Matrizes
Crie duas matrizes 3x3, some seus valores e exiba o resultado.
*/

#include <stdio.h>
#include <locale.h>  

int main() {
    // Definindo as duas matrizes 3x3 e a matriz de resultado
    int matriz1[3][3], matriz2[3][3], soma[3][3];
    int i, j;

    setlocale(LC_ALL, "portuguese");

    // Leitura da primeira matriz
    printf("Informe os elementos da primeira matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Leitura da segunda matriz
    printf("\nInforme os elementos da segunda matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Somando as duas matrizes e armazenando o resultado na matriz soma
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Exibindo o resultado da soma das matrizes
    printf("\nResultado da soma das duas matrizes 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", soma[i][j]);
        }
        printf("\n");
    }

    return 0;
}
