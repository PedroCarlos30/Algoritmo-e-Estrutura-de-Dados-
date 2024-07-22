//union :
//são usadas quando queremos armazenar valores heterogeneosem um 
//mesmo espaço de moemória;
//os paramentros compartilçham o mesmo espalo de memoria;
//so podemos armazenar um paramentro por vez;
#include<stdio.h>
#include<stdlib.h>

typedef union documentos{
    char cpf[11]; //formato 000.000.000-00
    long int rg; //apenas numeros inteiros 

}Documentos;

typedef struct pessoa{
    char nome[20]; //para guardar o nome completo da pessoa
    Documentos documentos;//para guardar o cpf ou rg

}Pessoa;

void preenche_pessoa(Pessoa *pessoa){
    /*Função para preencher struct pessoa.*/
    int opcao_documento;
    printf("Informe o nome: ");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe 1 - CPF ou 2 - RG: ");
    scanf("%d", &opcao_documento);
    switch (opcao_documento)
    {
    case 1:
        scanf(" %[^\n]", pessoa->documentos.cpf);
        break;
    case 2: 
        scanf("%ld", &pessoa->documentos.rg);
        break;
    default:
        printf("Valor invalido.");
        break;
    }
}

void imprime_pessoa(Pessoa *pessoa){
    printf("Nome: %s\nDocumento: %s\n", pessoa->nome, pessoa->documentos.cpf);
}

int main(void){
    Pessoa pessoa;
    preenche_pessoa(&pessoa);
    imprime_pessoa(&pessoa);
    return 0;
}