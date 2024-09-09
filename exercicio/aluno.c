#include "aluno.h"

struct aluno{
    int matricula;
    char nome[100];
    float media;
};

struct no{
    Aluno* aluno;
    No* prox;
};

No* adiona_aluno(No* lista, int matricula, char nome, float media){
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if(novo_aluno == NULL){
        printf("Erro.");
        exit(1);
    }
    novo_aluno->matricula = matricula;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->media = media;

    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro.");
        exit(1);
    }
    novo->aluno = novo_aluno;
    novo->prox = lista;
    return novo;
}

void imprime_aluno(No* lista){
    No* aux;
    for(aux = lista; aux != NULL; aux = aux->prox){
        printf("Nome:%s\tMatricula: %d\tMedia: %.1f",
        aux->aluno->nome, aux->aluno->matricula, aux->aluno->media);
    }
}

No* remove_aluno(No* lista, int matricula){
    No* aux;
    No* ant;
    if(lista->aluno->matricula == matricula){
        aux = lista->prox;
        free(lista->aluno);
        free(lista);
        return aux;
    }
    while(aux != NULL && aux->aluno->matricula != matricula){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Aluno nao encontrado.\n");
        return NULL;
    }
    ant->prox = aux->prox;
    free(aux->aluno);
    free(aux);
    return lista;
}

void libera_lista(No *lista){
    No* aux = lista;
    No* ant;
    while(aux != NULL){
        ant = aux;
        aux = aux->prox;
        free(ant->aluno);
        free(ant);
    }
}

No* adiciona_aluno_ordenado(No* lista, int matricula, char *nome, float media){
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if(novo_aluno == NULL){
        printf("Erro.");
        exit(1);
    }
    novo_aluno->matricula = matricula;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->media = media;
    No *novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro.");
        exit(1);
    }
    novo->aluno = novo_aluno;
    if(lista == NULL){
        novo->prox = NULL;
        return novo;
    }
    No *aux = lista;
    No *ant;
    while(aux != NULL && aux->aluno->matricula < matricula){
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = novo;
    novo->prox = aux;
    return lista;
}





























