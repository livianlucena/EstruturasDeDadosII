/*
Agenda de Contatos
Crie uma struct Contato e permita adicionar, buscar por nome e exibir todos os contatos.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>  // Para manipulação de strings

// Definindo a struct Contato
struct Contato {
    char nome[100];      // Nome do contato
    char telefone[20];   // Número de telefone do contato
    char email[100];     // E-mail do contato
};

int main() {
    int n, opcao;
    struct Contato contatos[100];  // Array para armazenar até 100 contatos
    int totalContatos = 0;

    setlocale(LC_ALL, "portuguese");  

    do {
        // Menu de opções
        printf("\n======= Agenda de Contatos =======\n");
        printf("1. Adicionar Contato\n");
        printf("2. Buscar Contato por Nome\n");
        printf("3. Exibir Todos os Contatos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Adicionar contato
                if (totalContatos < 100) {
                    printf("\nAdicionar Contato %d\n", totalContatos + 1);

                    printf("Nome: ");
                    getchar();  // Para consumir o '\n' deixado pelo scanf
                    fgets(contatos[totalContatos].nome, sizeof(contatos[totalContatos].nome), stdin);
                    contatos[totalContatos].nome[strcspn(contatos[totalContatos].nome, "\n")] = '\0';  // Remove o '\n' final da string

                    printf("Telefone: ");
                    fgets(contatos[totalContatos].telefone, sizeof(contatos[totalContatos].telefone), stdin);
                    contatos[totalContatos].telefone[strcspn(contatos[totalContatos].telefone, "\n")] = '\0';  // Remove o '\n' final

                    printf("E-mail: ");
                    fgets(contatos[totalContatos].email, sizeof(contatos[totalContatos].email), stdin);
                    contatos[totalContatos].email[strcspn(contatos[totalContatos].email, "\n")] = '\0';  // Remove o '\n' final

                    totalContatos++;  // Incrementa o número de contatos cadastrados
                } else {
                    printf("\nErro: Limite de contatos atingido.\n");
                }
                break;

            case 2:
                // Buscar contato por nome
                {
                    char nomeBusca[100];
                    printf("\nInforme o nome do contato para busca: ");
                    getchar();  // Para consumir o '\n' deixado pelo scanf anterior
                    fgets(nomeBusca, sizeof(nomeBusca), stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';  // Remove o '\n' final

                    int encontrado = 0;
                    for (int i = 0; i < totalContatos; i++) {
                        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
                            printf("\nContato encontrado:\n");
                            printf("Nome: %s\n", contatos[i].nome);
                            printf("Telefone: %s\n", contatos[i].telefone);
                            printf("E-mail: %s\n", contatos[i].email);
                            encontrado = 1;
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("\nContato com o nome %s não encontrado.\n", nomeBusca);
                    }
                }
                break;

            case 3:
                // Exibir todos os contatos
                printf("\nLista de Contatos:\n");
                if (totalContatos == 0) {
                    printf("Nenhum contato cadastrado.\n");
                } else {
                    for (int i = 0; i < totalContatos; i++) {
                        printf("\nContato %d:\n", i + 1);
                        printf("Nome: %s\n", contatos[i].nome);
                        printf("Telefone: %s\n", contatos[i].telefone);
                        printf("E-mail: %s\n", contatos[i].email);
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
