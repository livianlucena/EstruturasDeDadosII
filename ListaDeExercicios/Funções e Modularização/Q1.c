/*Números Primos em Intervalo
  Escreva uma função bool ehPrimo(int n) e use-a para listar todos os primos entre dois números dados pelo usuário.*/

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

bool ehPrimo(int n){
  int divisores=0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
        divisores++;
    }
  }

  if (divisores == 2) {
    return true; 
  } else {
    return false;
  }
}

int main(){
    setlocale(LC_ALL, "portuguese");

    int n1, n2;

    printf("====== Intervalo dos Números Primos ======\n\n");
    printf("Informe o número inicial: ");
    scanf("%d", &n1);
    printf("Informe o número final: ");
    scanf("%d", &n2);

    printf("\nNúmeros primos entre %d e %d:", n1, n2);

    for (int i = n1; i <= n2; i++) {
      if (ehPrimo(i)) {
          printf(" %d", i);
      }
  }

    return 0;
}