#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Produto {
    int codigo;
    char descricao[100];
    int quantidade;
};

Produto* criarProduto(int codigo, char* descricao, int quantidade) {
    Produto* novoProduto = (Produto*) malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro ao alocar memoria para o produto.\n");
        exit(1);
    }

    novoProduto->codigo = codigo;
    strcpy(novoProduto->descricao, descricao);
    novoProduto->quantidade = quantidade;
    return novoProduto;
}

void liberarProduto(Produto* produto) {
    free(produto);
}
