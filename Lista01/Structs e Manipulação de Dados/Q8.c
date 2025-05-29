/*
Estoque Simples
Crie uma struct Produto com nome, código, quantidade e preço. Permita cadastrar, buscar e listar produtos.
*/

#include <stdio.h>
#include <locale.h>  
#include <string.h>  // Para manipulação de strings

// Definindo a struct Produto
struct Produto {
    char nome[100];    // Nome do produto
    int codigo;        // Código do produto
    int quantidade;    // Quantidade em estoque
    float preco;       // Preço do produto
};

int main() { 
    int n, opcao, codigoBusca;
    struct Produto produtos[100];  // Array para armazenar até 100 produtos
    int totalProdutos = 0;

    setlocale(LC_ALL, "portuguese"); 

    do {
        // Menu de opções
        printf("\n======= Controle de Estoque =======\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Buscar Produto\n");
        printf("3. Listar Produtos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Cadastro de produto
                if (totalProdutos < 100) {
                    printf("\nCadastro de Produto %d\n", totalProdutos + 1);

                    printf("Nome: ");
                    getchar();  // Para consumir o '\n' deixado pelo scanf
                    fgets(produtos[totalProdutos].nome, sizeof(produtos[totalProdutos].nome), stdin);
                    produtos[totalProdutos].nome[strcspn(produtos[totalProdutos].nome, "\n")] = '\0';  // Remove o '\n' final da string

                    printf("Código: ");
                    scanf("%d", &produtos[totalProdutos].codigo);

                    printf("Quantidade: ");
                    scanf("%d", &produtos[totalProdutos].quantidade);

                    printf("Preço: ");
                    scanf("%f", &produtos[totalProdutos].preco);

                    totalProdutos++;  // Incrementa o número de produtos cadastrados
                } else {
                    printf("\nErro: Limite de produtos atingido.\n");
                }
                break;

            case 2:
                // Buscar produto
                printf("\nInforme o código do produto para busca: ");
                scanf("%d", &codigoBusca);

                int encontrado = 0;
                for (int i = 0; i < totalProdutos; i++) {
                    if (produtos[i].codigo == codigoBusca) {
                        printf("\nProduto encontrado:\n");
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Código: %d\n", produtos[i].codigo);
                        printf("Quantidade: %d\n", produtos[i].quantidade);
                        printf("Preço: %.2f\n", produtos[i].preco);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("\nProduto com código %d não encontrado.\n", codigoBusca);
                }
                break;

            case 3:
                // Listar produtos
                printf("\nLista de Produtos:\n");
                if (totalProdutos == 0) {
                    printf("Nenhum produto cadastrado.\n");
                } else {
                    for (int i = 0; i < totalProdutos; i++) {
                        printf("\nProduto %d:\n", i + 1);
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Código: %d\n", produtos[i].codigo);
                        printf("Quantidade: %d\n", produtos[i].quantidade);
                        printf("Preço: %.2f\n", produtos[i].preco);
                    }
                }
                break;

            case 4:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}
