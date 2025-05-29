#include <stdio.h>   
#include <stdlib.h> 

// Estrutura do nó da árvore
typedef struct No {
    int dado;                // Valor armazenado
    struct No* esquerdo;     // Ponteiro para filho esquerdo
    struct No* direito;      // Ponteiro para filho direito
} No;

// Criar novo nó com valor
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo != NULL) {
        novo->dado = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

// Inserir valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);
    if (valor < raiz->dado)
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    else if (valor > raiz->dado)
        raiz->direito = inserir(raiz->direito, valor);
    return raiz;
}

// Buscar valor na árvore
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor)
        return raiz;
    if (valor < raiz->dado)
        return buscar(raiz->esquerdo, valor);
    return buscar(raiz->direito, valor);
}

// Percurso In-Ordem (esquerda, raiz, direita)
void inOrdem(No* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        inOrdem(raiz->direito);
    }
}

// Percurso Pré-Ordem (raiz, esquerda, direita)
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

// Percurso Pós-Ordem (esquerda, direita, raiz)
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}

// Calcular altura da árvore
int altura(No* raiz) {
    if (raiz == NULL) return -1;
    int esq = altura(raiz->esquerdo);
    int dir = altura(raiz->direito);
    return (esq > dir ? esq : dir) + 1;
}

// Soma de todos os valores da árvore
int somaNos(No* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dado + somaNos(raiz->esquerdo) + somaNos(raiz->direito);
}

// Contar total de nós
int contarNos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerdo) + contarNos(raiz->direito);
}

// Contar total de folhas (nós sem filhos)
int contarFolhas(No* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerdo == NULL && raiz->direito == NULL)
        return 1;
    return contarFolhas(raiz->esquerdo) + contarFolhas(raiz->direito);
}

// Profundidade de um valor (nível a partir da raiz)
int profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return nivel;
    if (valor < raiz->dado)
        return profundidade(raiz->esquerdo, valor, nivel + 1);
    return profundidade(raiz->direito, valor, nivel + 1);
}

// Nível de um nó (atalho chamando profundidade com 0)
int nivel(No* raiz, int valor) {
    return profundidade(raiz, valor, 0);
}

// Remover todos os nós (liberar memória)
void removerArvore(No* raiz) {
    if (raiz != NULL) {
        removerArvore(raiz->esquerdo);
        removerArvore(raiz->direito);
        free(raiz);
    }
}

// Função principal para testes
int main() {
    No* raiz = NULL;

    // Inserção de elementos
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 24);
    raiz = inserir(raiz, 10);

    // Exibir percursos
    printf("In-Ordem: ");
    inOrdem(raiz);
    printf("\n");

    printf("Pré-Ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Pós-Ordem: ");
    posOrdem(raiz);
    printf("\n");

    // Estatísticas da árvore
    printf("Altura da árvore: %d\n", altura(raiz));
    printf("Soma dos valores: %d\n", somaNos(raiz));
    printf("Total de nós: %d\n", contarNos(raiz));
    printf("Total de folhas: %d\n", contarFolhas(raiz));

    // Buscar valor e mostrar profundidade
    int valorBusca = 40;
    No* encontrado = buscar(raiz, valorBusca);
    if (encontrado != NULL) {
        printf("Valor %d encontrado na árvore.\n", valorBusca);
        printf("Profundidade: %d\n", profundidade(raiz, valorBusca, 0));
        printf("Nível: %d\n", nivel(raiz, valorBusca));
    } else {
        printf("Valor %d não encontrado na árvore.\n", valorBusca);
    }

    // Liberação de memória
    removerArvore(raiz);
    return 0;
}
