#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno {
    int matricula;
    char nome[100];
    float media;
};

Aluno* criarAluno(int matricula, char* nome, float media) {
    Aluno* novoAluno = (Aluno*) malloc(sizeof(Aluno));
    if (novoAluno == NULL) {
        printf("Erro ao alocar memoria para o aluno.\n");
        exit(1);
    }

    novoAluno->matricula = matricula;
    strcpy(novoAluno->nome, nome);
    novoAluno->media = media;
    return novoAluno;
}

void liberarAluno(Aluno* aluno) {
    free(aluno);
}
