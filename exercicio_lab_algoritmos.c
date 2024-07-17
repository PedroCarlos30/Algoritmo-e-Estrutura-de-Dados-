#include <stdio.h>
#include <stdlib.h>
#define Quantidade_Alunos 5

typedef struct aluno
{
   int mat, idade;
   char nome[20];
}Aluno;

void preenche(Aluno*aluno, int tamanho ){
     int count;
    for(count = 0; count < tamanho; count++){
        printf("Informe o nome:\t");
        scanf(" %[^\n]", aluno[count].nome);
        printf("Informe sua matricula:\t");
        scanf("%d", &aluno[count].mat);
        printf("Informe a sua idade:\t");
        scanf("%d", &aluno[count].idade);
    }
}

int main(void){
    Aluno *aluno = (Aluno*) malloc (Quantidade_Alunos*sizeof(Aluno));
    if(aluno == NULL){
        printf("No memory RAM");
        exit(1);
    }

    preenche(aluno, Quantidade_Alunos);

    int novo_tamanho;
    printf("Informe o novo tamanho do vetor: \t");
    scanf("%d", &novo_tamanho);
    aluno = (Aluno*) realloc (aluno, novo_tamanho*sizeof(Aluno));
    if(aluno == NULL){
        printf("No memory RAM");
        exit(1);
    }
    preenche(aluno, novo_tamanho);
    return 0;
}