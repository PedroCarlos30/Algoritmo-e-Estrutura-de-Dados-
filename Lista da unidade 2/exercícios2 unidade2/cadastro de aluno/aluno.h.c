#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno Aluno;

Aluno* criarAluno(int matricula, char* nome, float media);
void liberarAluno(Aluno* aluno);

#endif
