#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5


typedef struct {
    char nome;
    int id;
} Peca;


typedef struct {
    Peca pecas[TAMANHO_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;


int contadorID = 0;


Peca gerarPeca() {

    char tipos[] = {'I', 'O', 'T', 'L'};
    
    Peca novaPeca;

    novaPeca.nome = tipos[rand() % 4];
    novaPeca.id = contadorID++;

    return novaPeca;
}


void inicializarFila(Fila *fila) {

    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}


int filaVazia(Fila *fila) {
    return fila->quantidade == 0;
}


int filaCheia(Fila *fila) {
    return fila->quantidade == TAMANHO_FILA;
}


void enqueue(Fila *fila, Peca novaPeca) {

    if (filaCheia(fila)) {
        printf("\nFila cheia! Não é possível inserir nova peça.\n");
        return;
    }

    fila->pecas[fila->fim] = novaPeca;

    fila->fim = (fila->fim + 1) % TAMANHO_FILA;

    fila->quantidade++;

    printf("\nPeça [%c %d] inserida na fila.\n",
           novaPeca.nome,
           novaPeca.id);
}


void dequeue(Fila *fila) {

    if (filaVazia(fila)) {
        printf("\nFila vazia! Nenhuma peça para jogar.\n");
        return;
    }

    Peca removida = fila->pecas[fila->inicio];

    fila->inicio = (fila->inicio + 1) % TAMANHO_FILA;

    fila->quantidade--;

    printf("\nPeça [%c %d] jogada!\n",
           removida.nome,
           removida.id);
}


void exibirFila(Fila *fila) {

    printf("\n=== FILA DE PEÇAS ===\n");

    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    int i;
    int indice = fila->inicio;

    for (i = 0; i < fila->quantidade; i++) {

        printf("[%c %d] ",
               fila->pecas[indice].nome,
               fila->pecas[indice].id);

        indice = (indice + 1) % TAMANHO_FILA;
    }

    printf("\n");
}

// Programa principal
int main() {

    srand(time(NULL));

    Fila fila;

    inicializarFila(&fila);

    // Inserindo 5 peças iniciais
    for (int i = 0; i < TAMANHO_FILA; i++) {
        enqueue(&fila, gerarPeca());
    }

    int opcao;

    do {

        exibirFila(&fila);

        printf("\n=== MENU ===\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                dequeue(&fila);
                break;

            case 2:
                enqueue(&fila, gerarPeca());
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}