#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[100];
int quantidadeItens = 0;


void listarItens() {
    printf("\nItens na mochila:\n");

    if (quantidadeItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < quantidadeItens; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}


int BuscarItens(char nome[]) {
    for (int i = 0; i < quantidadeItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
} 


void InserirItem() {
    if (quantidadeItens >= 100) {
        printf("A mochila está cheia.\n");
        return;
    }

    Item novo;

    printf("Digite o nome do item: ");
    scanf("%s", novo.nome);

    printf("Digite o tipo do item: ");
    scanf("%s", novo.tipo);

    printf("Digite a quantidade do item: ");
    scanf("%d", &novo.quantidade);

    mochila[quantidadeItens] = novo;
    quantidadeItens++;

    printf("Item inserido com sucesso!\n");
}


void RemoverItem() {
    char nome[30];

    printf("Digite o nome do item a ser removido: ");
    scanf("%s", nome);

    int pos = BuscarItens(nome);

    if (pos == -1) {
        printf("Item não encontrado.\n");
        return;
    }

    for (int i = pos; i < quantidadeItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    quantidadeItens--;
    printf("Item removido com sucesso!\n");
}


void BuscarItem() {
    char nome[30];

    printf("Digite o nome do item a ser buscado: ");
    scanf("%s", nome);

    int pos = BuscarItens(nome);

    if (pos == -1) {
        printf("Item não encontrado.\n");
        return;
    }

    printf("\nItem encontrado:\n");
    printf("Nome: %s\n", mochila[pos].nome);
    printf("Tipo: %s\n", mochila[pos].tipo);
    printf("Quantidade: %d\n", mochila[pos].quantidade);
}


int main() {
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Listar Itens\n");
        printf("2. Inserir Item\n");
        printf("3. Remover Item\n");
        printf("4. Buscar Item\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarItens();
                break;
            case 2:
                InserirItem();
                break;
            case 3:
                RemoverItem();
                break;
            case 4:
                BuscarItem();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

        if (opcao != 5) {
            listarItens();
        }

    } while (opcao != 5);

    return 0;
}
// Codigo feito para aprendizado criando um sistema de inventário simples para um jogo de RPG. 
// O código permite ao usuário listar, inserir, remover e buscar itens em uma mochila. Cada item tem um nome, tipo e quantidade. O programa utiliza um array para armazenar os itens e funções para manipular o inventário.
