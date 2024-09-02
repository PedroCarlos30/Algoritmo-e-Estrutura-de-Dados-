#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

struct ContaBancaria {
    char* titular;
    int numero;
    double saldo;
};

ContaBancaria* criaConta(char* titular, int numero, double saldo) {
    ContaBancaria* novaConta = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    if (novaConta == NULL) {
        printf("Erro ao alocar memoria para a conta.\n");
        exit(1);
    }

    novaConta->titular = titular;
    novaConta->numero = numero;
    novaConta->saldo = saldo;
    return novaConta;
}

void deposita(ContaBancaria* conta, double valor) {
    conta->saldo += valor;
}

int saca(ContaBancaria* conta, double valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        return 1; // Sucesso
    } else {
        printf("Saldo insuficiente para saque.\n");
        return 0; // Falha
    }
}

int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor) {
    if (saca(origem, valor)) {
        deposita(destino, valor);
        return 1; // Sucesso
    } else {
        return 0; // Falha
    }
}

double saldo(ContaBancaria* conta) {
    return conta->saldo;
}

void excluiConta(ContaBancaria* conta) {
    free(conta);
}
