#include<stdio.h>
#include<stdlib.h>

typedef struct aluno{
    char nome[20];
    int idade;
    long int matricula;
}Aluno;

void preenche(Aluno*aluno){
    printf("Informe o nome:\t");
    scanf("%[^\n]", aluno->nome);
    printf("Informe idade e matricula:\t");
    scanf("%d %d", &aluno->idade, &aluno->matricula);
}

void imprime(Aluno*aluno){
    printf("Nome:%s\tIdade:%ld\tMatricula:%ld", aluno->nome, aluno->idade, aluno->matricula);
}