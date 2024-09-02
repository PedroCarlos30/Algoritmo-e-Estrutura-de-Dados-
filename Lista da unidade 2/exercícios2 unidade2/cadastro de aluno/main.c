#include <stdio.h>
#include "aluno.h"

void criarArquivoVazio(char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }
    fclose(arquivo);
}

void salvarAlunoEmArquivo(char* nomeArquivo, Aluno* aluno) {
    FILE* arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    fprintf(arquivo, "%d;%s;%.2f\n", aluno->matricula, aluno->nome, aluno->media);
    fclose(arquivo);
}

void exibirAlunos(char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    int matricula;
    char nome[100];
    float media;

    printf("Alunos cadastrados:\n");
    while (fscanf(arquivo, "%d;%[^;];%f\n", &matricula, nome, &media) == 3) {
        printf("Matricula: %d, Nome: %s, Media: %.2f\n", matricula, nome, media);
    }

    fclose(arquivo);
}

int main() {
    criarArquivoVazio("alunos.txt");

    Aluno* aluno1 = criarAluno(123, "Maria", 8.5);
    salvarAlunoEmArquivo("alunos.txt", aluno1);
    liberarAluno(aluno1);

    Aluno* aluno2 = criarAluno(456, "Joao", 7.0);
    salvarAlunoEmArquivo("alunos.txt", aluno2);
    liberarAluno(aluno2);

    exibirAlunos("alunos.txt");

    return 0;
}
