#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto Produto;

Produto* criarProduto(int codigo, char* descricao, int quantidade);
void liberarProduto(Produto* produto);

#endif
