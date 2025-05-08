/*
Inverso de Número
Escreva uma função que inverte os dígitos de um número (ex: 1234 → 4321).
*/

#include <stdio.h>
#include <locale.h>



int inverterNumero(int numero) {
    int invertido = 0;
    int negativo = 0;

    // Verifica se o número é negativo
    if (numero < 0) {
        negativo = 1;
        numero = -numero; // Torna positivo para facilitar a inversão
    }

    // Inversão dos dígitos
    while (numero != 0) {
        int digito = numero % 10;
        invertido = invertido * 10 + digito;
        numero /= 10;
    }

    // Retorna com sinal correto
    if (negativo) {
        invertido = -invertido;
    }

    return invertido;
}

int main() {
    int numero;

    setlocale(LC_ALL, "portuguese"); 

    printf("====== Inverso de Números ======\n\n");
    printf("Informe um número: ");
    scanf("%d", &numero);

    int resultado = inverterNumero(numero);
    printf("Número invertido: %d\n", resultado);

    return 0;
}
