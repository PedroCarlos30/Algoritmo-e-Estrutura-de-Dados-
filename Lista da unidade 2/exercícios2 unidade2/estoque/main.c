#include <stdio.h>
#include "produto.h"

void criarArquivoEstoque(char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de estoque.\n");
        exit(1);
    }
    fclose(arquivo);
}

void adicionarProdutoAoEstoque(char* nomeArquivo, Produto* produto) {
    FILE* arquivo = fopen(nomeArquivo, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    fwrite(produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
}

void removerProdutoDoEstoque(char* nomeArquivo, int codigo) {
    FILE* arquivo = fopen(nomeArquivo, "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        exit(1);
    }

    FILE* tempArquivo = fopen("temp.bin", "wb");
    if (tempArquivo == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arquivo);
        exit(1);
    }

    Produto produto;
    while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
        if (produto.codigo != codigo) {
            fwrite(&produto, sizeof(Produto), 1, tempArquivo);
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);
    remove(nomeArquivo);
    rename("temp.bin", nomeArquivo);
}

void atualizarQuantidadeEmEstoque(char* nomeArquivo, int codigo, int novaQuantidade) {
    FILE* arquivo = fopen(nomeArquivo, "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        exit(1);
    }

    Produto produto;
    while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
        if (produto.codigo == codigo) {
            produto.quantidade = novaQuantidade;
            fseek(arquivo, -sizeof(Produto), SEEK_CUR);
            fwrite(&produto, sizeof(Produto), 1, arquivo);
            break;
        }
    }

    fclose(arquivo);
}

void exibirEstoque(char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    Produto produto;
    printf("Produtos em estoque:\n");
    while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
        printf("Codigo: %d, Descricao: %s, Quantidade: %d\n", produto.codigo, produto.descricao, produto.quantidade);
    }

    fclose(arquivo);
}

int main() {
    criarArquivoEstoque("estoque.bin");

    Produto* produto1 = criarProduto(101, "Cadeira", 15);
    adicionarProdutoAoEstoque("estoque.bin", produto1);
    liberarProduto(produto1);

    Produto* produto2 = criarProduto(102, "Mesa", 8);
    adicionarProdutoAoEstoque("estoque.bin", produto2);
    liberarProduto(produto2);

    exibirEstoque("estoque.bin");

    atualizarQuantidadeEmEstoque("estoque.bin", 101, 10);
    removerProdutoDoEstoque("estoque.bin", 102);

    printf("\nEstoque apos atualizacoes:\n");
    exibirEstoque("estoque.bin");

    return 0;
}
