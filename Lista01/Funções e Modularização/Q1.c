/*
Números Primos em Intervalo
Escreva uma função bool ehPrimo(int n) e use-a para listar todos os primos entre dois números dados pelo usuário.
*/

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>  // Biblioteca para usar o tipo booleano (true/false)

// Função que verifica se um número é primo
bool ehPrimo(int n) {
  int divisores = 0;

  // Conta quantos divisores o número possui
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
       divisores++;
    }
  }

  // Um número é primo se tiver exatamente dois divisores: 1 e ele mesmo
  if (divisores == 2) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n1, n2;

  setlocale(LC_ALL, "portuguese");  

  // Entrada de dados
  printf("====== Intervalo dos Números Primos ======\n\n");
  printf("Informe o número inicial: ");
  scanf("%d", &n1);
  printf("Informe o número final: ");
  scanf("%d", &n2);

  // Verifica se o intervalo é válido
  if (n1 > n2) {
    printf("\nErro: o número inicial (%d) não pode ser maior que o número final (%d).\n", n1, n2);
    return 1;  // Encerra o programa com código de erro
  } else {
    // Impressão dos primos dentro do intervalo fornecido
    printf("\nNúmeros primos entre %d e %d:", n1, n2);

    for (int i = n1; i <= n2; i++) {
      if (ehPrimo(i)) {
        printf(" %d", i);  // Imprime o número primo
      }
    }
  }

  return 0;
}
