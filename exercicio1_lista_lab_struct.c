#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct funcionario{
    char nome[20], cargo[20];
    float salario;
    long int indentificado;
}Funcionario;

void preenche(Funcionario * servidor){
    setlocale(LC_ALL, "Portuguese");
    /*função para preenche variavel do tipo funcionario.*/
    printf("Digite o nome: ");
    scanf(" %[^\n]", servidor->nome);
    printf("Digite seu salario: ");
    scanf("%f", &servidor->salario);
    printf("Digite seu identificador: ");
    scanf("%d", &servidor->indentificado);
     printf("Digite seu cargo: ");
    scanf(" %[^\n]", servidor->cargo);
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    Funcionario *servidor = (Funcionario*) malloc (2*sizeof(Funcionario));
    preenche(servidor);
    
    printf("\nnome: %s\n", servidor->nome);
    printf("salário: %.2f\n", servidor->salario);
    printf("identificador: %d\n", servidor->indentificado);
    printf("cargo: %s\n", servidor->cargo);
    return 0;
}