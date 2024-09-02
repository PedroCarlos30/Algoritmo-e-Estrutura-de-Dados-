#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_DISCIPLINAS 10

struct Aluno {
    char nome[100];
    int matricula;
    Disciplina* disciplinas[MAX_DISCIPLINAS];
    int num_disciplinas;
};

Aluno* cria_aluno(char nome[], int matricula) {
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if (novo_aluno == NULL) {
        printf("Erro ao alocar memoria para o aluno.\n");
        exit(1);
    }

    strcpy(novo_aluno->nome, nome);
    novo_aluno->matricula = matricula;
    novo_aluno->num_disciplinas = 0;
    return novo_aluno;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina) {
    if (aluno->num_disciplinas < MAX_DISCIPLINAS) {
        // Verificar se a disciplina já está matriculada
        for (int i = 0; i < aluno->num_disciplinas; i++) {
            if (aluno->disciplinas[i]->codigo == disciplina->codigo) {
                printf("Aluno ja matriculado na disciplina %s.\n", disciplina->nome);
                return;
            }
        }

        aluno->disciplinas[aluno->num_disciplinas++] = disciplina;
    } else {
        printf("Limite de disciplinas atingido para o aluno %s.\n", aluno->nome);
    }
}

void exclui_aluno(Aluno* aluno) {
    free(aluno);
}
