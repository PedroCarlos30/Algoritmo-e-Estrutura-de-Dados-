#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct Disciplina Disciplina;

Disciplina* cria_disciplina(char nome[], int codigo);
void exclui_disciplina(Disciplina* disciplina);

#endif
