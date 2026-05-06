#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int numeroConta;
    float saldo;
} ContaBancaria;



void criarConta(ContaBancaria contas[], int *total) {
    if (*total >= MAX) {
        printf("Limite de contas atingido!\n");
        return;
    }

    printf("\n----- CRIAR CONTA -----\n");

    printf("Nome do titular: ");
    scanf(" %[^\n]", contas[*total].nome);

    
    if (strlen(contas[*total].nome) == 0) {
        printf("Nome invalido!\n");
        return;
    }

    printf("Numero da conta: ");
    scanf("%d", &contas[*total].numeroConta);

    contas[*total].saldo = 0.0;

    printf("\nConta criada com sucesso!\n");
    printf("Titular: %s\n", contas[*total].nome);
    printf("Numero: %d\n", contas[*total].numeroConta);

    (*total)++;
}



int buscarConta(ContaBancaria contas[], int total, int numero) {
    for (int i = 0; i < total; i++) {
        if (contas[i].numeroConta == numero) {
            return i;
        }
    }
    return -1;
}



void depositar(ContaBancaria contas[], int total) {
    int numero;
    float valor;

    printf("\n----- DEPOSITO -----\n");

    printf("Numero da conta: ");
    scanf("%d", &numero);

    int i = buscarConta(contas, total, numero);

    if (i == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }

    printf("Valor: ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor invalido!\n");
        return;
    }

    contas[i].saldo += valor;
    printf("Deposito realizado com sucesso!\n");
}



void sacar(ContaBancaria contas[], int total) {
    int numero;
    float valor;

    printf("\n----- SAQUE -----\n");

    printf("Numero da conta: ");
    scanf("%d", &numero);

    int i = buscarConta(contas, total, numero);

    if (i == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }

    printf("Valor: ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor invalido!\n");
        return;
    }

    if (contas[i].saldo >= valor) {
        contas[i].saldo -= valor;
        printf("Saque realizado com sucesso!\n");
    } else {
        printf("Saldo insuficiente!\n");
    }
}



void consultarSaldo(ContaBancaria contas[], int total) {
    int numero;

    printf("\n----- CONSULTAR SALDO -----\n");

    printf("Numero da conta: ");
    scanf("%d", &numero);

    int i = buscarConta(contas, total, numero);

    if (i == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }

    printf("Titular: %s\n", contas[i].nome);
    printf("Saldo: R$%.2f\n", contas[i].saldo);
}



void listarContas(ContaBancaria contas[], int total) {
    printf("\n----- LISTA DE CONTAS -----\n");

    if (total == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nConta %d\n", i + 1);
        printf("Titular: %s\n", contas[i].nome);
        printf("Numero: %d\n", contas[i].numeroConta);
        printf("Saldo: R$%.2f\n", contas[i].saldo);
    }
}



void menu() {
    printf("\n==============================\n");
    printf("     SISTEMA BANCARIO\n");
    printf("==============================\n");
    printf("1 - Criar Conta\n");
    printf("2 - Depositar\n");
    printf("3 - Sacar\n");
    printf("4 - Consultar Saldo\n");
    printf("5 - Listar Contas\n");
    printf("0 - Sair\n");
    printf("==============================\n");
    printf("Opcao: ");
}



int main() {
    ContaBancaria contas[MAX];
    int total = 0;
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarConta(contas, &total);
                break;
            case 2:
                depositar(contas, total);
                break;
            case 3:
                sacar(contas, total);
                break;
            case 4:
                consultarSaldo(contas, total);
                break;
            case 5:
                listarContas(contas, total);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}