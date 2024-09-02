#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"

int main() {
    Disciplina* disciplina1 = cria_disciplina("Matematica", 101);
    Disciplina* disciplina2 = cria_disciplina("Portugues", 102);

    Aluno* aluno1 = cria_aluno("Joao", 12345);
    Aluno* aluno2 = cria_aluno("Maria", 67890);

    matricula_disciplina(aluno1, disciplina1);
    matricula_disciplina(aluno1, disciplina2);
    matricula_disciplina(aluno2, disciplina1);

    printf("Aluno: %s, Matricula: %d\n", aluno1->nome, aluno1->matricula);
    for (int i = 0; i < aluno1->num_disciplinas; i++) {
        printf("  - Disciplina: %s, Codigo: %d\n", aluno1->disciplinas[i]->nome, aluno1->disciplinas[i]->codigo);
    }

    printf("\nAluno: %s, Matricula: %d\n", aluno2->nome, aluno2->matricula);
    for (int i = 0; i < aluno2->num_disciplinas; i++) {
        printf("  - Disciplina: %s, Codigo: %d\n", aluno2->disciplinas[i]->nome, aluno2->disciplinas[i]->codigo);
    }

    exclui_aluno(aluno1);
    exclui_aluno(aluno2);
    exclui_disciplina(disciplina1);
    exclui_disciplina(disciplina2);

    return 0;
}
