#include "lista_fruta.h"
//defini a estrutura para frutas
struct fruta{
    char nome[50];
    float valor_por_kg;
};
//definir uma lista duplamente encadeada para armazenar as frutas
struct no{
    Fruta * fruta;
    struct No * prox;
    struct No * ant;
};
//definir uma função que cria um nó na lista
No * criaNo(char * nome_para_fruta, float valor_por_kg ){
    No * nova_fruta = (No*) malloc(sizeof(No));
    nova_fruta->fruta = (Fruta*) malloc(sizeof(Fruta));
    if(nova_fruta == NULL){
        printf("Computador sem memoria!\n");
        exit(1);
    }
    else{
        printf("Memoria alocada! \n Espaco para fruta resercado!\n");
        strcpy(nova_fruta->fruta->nome, nome_para_fruta);
        nova_fruta->fruta->valor_por_kg = valor_por_kg;
        nova_fruta->prox = NULL;
        nova_fruta->ant = NULL;
    }
    return nova_fruta;
}
//definir a função que ensere o Nó no inicio da lista
No * inserirNoInicio(No * lista, char * nome_para_fruta, float valor_por_kg){
    No * nova_fruta = criaNo(nome_para_fruta, valor_por_kg);
    //verificar se a lista é vazia
    if(lista == NULL){
        lista = nova_fruta;
    }
    else{
        nova_fruta->prox = lista;
        lista->ant = nova_fruta;
    }
    return nova_fruta;
}
//definir a função que imprime as frutas
void exibirListaDeFrutas(No * lista){
    if(!lista)/*verifica se a lista esta vazia = lista == NULL*/{
        printf("Lista vazia! Sem frutas cadastradas.\n");
        exit(1);
    }
    No * contador = lista;//contador para percorrer a lista
    while(contador != NULL){
        printf("Fruta: %s, Valor (Kg): R$ %.2f\n", contador->fruta->nome, contador->fruta->valor_por_kg);
        contador = contador->prox;
    } 
}