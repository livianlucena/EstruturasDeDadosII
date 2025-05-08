/*Potência (sem usar pow)
  Implemente uma função int potencia(int base, int expoente) que calcule potências usando apenas multiplicações.*/

#include <stdio.h>
#include <locale.h>

int potencia(int base, int expoente){
    int produto = 1;
    for(int i = 0; i < expoente; i++){
        produto *= base;
    }
    return produto;
}

int main (){
    setlocale(LC_ALL,"portuguese");

    int base, expoente;

    printf("====== Calcular Potência ======\n\n");
    printf("Informe a base: ");
    scanf("%d", &base);
    printf("Informe o expoente: ");
    scanf("%d", &expoente);

    int produto = potencia(base, expoente);

    printf("\nO valor de %d^%d = %d\n", base, expoente, produto);

    return 0;
}