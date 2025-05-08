/*
Cadastro de Alunos
Crie uma struct Aluno com nome, matrícula e média. Cadastre n alunos e mostre os aprovados.
*/

#include <stdio.h>
#include <locale.h>  

// Definindo a struct Aluno
struct Aluno {
    char nome[100];    // Nome do aluno
    int matricula;     // Matrícula do aluno
    float media;       // Média do aluno
};

int main() {
    int n;

    setlocale(LC_ALL, "portuguese"); 
    
    // Pergunta o número de alunos a serem cadastrados
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    // Criando um vetor de structs Aluno
    struct Aluno alunos[n];

    // Cadastro dos alunos
    for (int i = 0; i < n; i++) {
        printf("\nCadastro do aluno %d\n", i + 1);

        printf("Nome: ");
        getchar();  // Para consumir o '\n' deixado pelo scanf anterior
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Média: ");
        scanf("%f", &alunos[i].media);
    }

    // Exibindo os alunos aprovados
    printf("\nAlunos aprovados (Média >= 6.0):\n");
    for (int i = 0; i < n; i++) {
        if (alunos[i].media >= 6.0) {
            printf("\nNome: %s", alunos[i].nome);
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Média: %.2f\n", alunos[i].media);
        }
    }

    return 0;
}
