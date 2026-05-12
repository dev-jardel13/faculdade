#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[30];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

Sala* criarSala(char nome[]) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));

    if (novaSala == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}
 void explorarSalas(Sala* atual) {

    char opcao;

    
    while (atual != NULL) {

        printf("\nVocê está em: %s\n", atual->nome);

      
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou ao fim deste caminho!\n");
            break;
        }

        
        if (atual->esquerda != NULL) {
            printf("e - Ir para esquerda\n");
        }

        if (atual->direita != NULL) {
            printf("d - Ir para direita\n");
        }

        printf("s - Sair\n");

        printf("Escolha: ");
        scanf(" %c", &opcao);

        if (opcao == 'e') {

            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("Não existe caminho à esquerda!\n");
            }

        } else if (opcao == 'd') {

            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Não existe caminho à direita!\n");
            }

        } else if (opcao == 's') {

            printf("Exploração encerrada.\n");
            break;

        } else {

            printf("Opção inválida!\n");
        }
    }
}


int main() {

   
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* jantar = criarSala("Sala de Jantar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* escritorio = criarSala("Escritorio");
    Sala* jardim = criarSala("Jardim");
    Sala* porao = criarSala("Porao");

    hall->esquerda = biblioteca;
    hall->direita = jantar;

    biblioteca->esquerda = cozinha;
    biblioteca->direita = escritorio;

    jantar->esquerda = jardim;
    jantar->direita = porao;

  
    explorarSalas(hall);

    return 0;
}