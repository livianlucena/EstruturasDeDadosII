#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da árvore (aluno)
typedef struct Aluno {
    char nome[50];              // Nome do aluno
    int matricula;              // Matrícula do aluno
    float nota;                 // Nota do aluno
    struct Aluno* esquerdo;     // Filho à esquerda
    struct Aluno* direito;      // Filho à direita
} Aluno;

// Função para criar um novo aluno
Aluno* criarAluno(char* nome, int matricula, float nota) {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo != NULL) {
        strcpy(novo->nome, nome);       // Copia o nome para o campo
        novo->matricula = matricula;    // Define a matrícula
        novo->nota = nota;              // Define a nota
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

// Inserir aluno na árvore de forma ordenada por nome
Aluno* inserirAluno(Aluno* raiz, char* nome, int matricula, float nota) {
    if (raiz == NULL)
        return criarAluno(nome, matricula, nota);

    // Compara nomes para decidir lado
    if (strcmp(nome, raiz->nome) < 0)
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    else if (strcmp(nome, raiz->nome) > 0)
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);

    return raiz;
}

// Buscar aluno pelo nome na árvore
Aluno* buscarAluno(Aluno* raiz, char* nome) {
    if (raiz == NULL || strcmp(raiz->nome, nome) == 0)
        return raiz;

    if (strcmp(nome, raiz->nome) < 0)
        return buscarAluno(raiz->esquerdo, nome);
    return buscarAluno(raiz->direito, nome);
}

// Soma das notas de todos os alunos (usada para média)
float somaNotas(Aluno* raiz) {
    if (raiz == NULL) return 0;
    return raiz->nota + somaNotas(raiz->esquerdo) + somaNotas(raiz->direito);
}

// Conta o total de alunos na árvore
int contarAlunos(Aluno* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarAlunos(raiz->esquerdo) + contarAlunos(raiz->direito);
}

// Calcula a média das notas dos alunos
float mediaNotas(Aluno* raiz) {
    int total = contarAlunos(raiz);
    if (total == 0) return 0;
    return somaNotas(raiz) / total;
}

// Função para liberar toda a memória da árvore
void removerArvoreAlunos(Aluno* raiz) {
    if (raiz != NULL) {
        removerArvoreAlunos(raiz->esquerdo);  // Remove esquerda
        removerArvoreAlunos(raiz->direito);   // Remove direita
        free(raiz);                           // Libera o próprio nó
    }
}

// Função principal para testes
int main() {
    Aluno* raiz = NULL;  // Inicializa árvore vazia

    // Inserção de alguns alunos
    raiz = inserirAluno(raiz, "Jordan", 1000, 10.0);
    raiz = inserirAluno(raiz, "Lívian", 1001, 8.0);
    raiz = inserirAluno(raiz, "Izadora", 1002, 8.5);
    raiz = inserirAluno(raiz, "Hellen", 1003, 8.5);

    // Calcula e imprime a média das notas
    float media = mediaNotas(raiz);
    printf("Média das notas dos alunos: %.2f\n", media);

    // Busca por aluno específico
    char nomeBusca[50] = "Jordan";
    Aluno* encontrado = buscarAluno(raiz, nomeBusca);

    // Exibe resultado da busca
    if (encontrado != NULL) {
        printf("Aluno encontrado:\n");
        printf("Nome: %s\n", encontrado->nome);
        printf("Matrícula: %d\n", encontrado->matricula);
        printf("Nota: %.2f\n", encontrado->nota);
    } else {
        printf("Aluno com nome '%s' não encontrado.\n", nomeBusca);
    }

    // Libera toda a memória alocada
    removerArvoreAlunos(raiz);

    return 0;
}
