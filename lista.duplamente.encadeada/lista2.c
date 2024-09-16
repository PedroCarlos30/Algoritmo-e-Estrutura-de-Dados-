#include "lista2.h"

struct lista2
{
    int info; 
    struct lista2* ant;
    struct lista2* prox;    
};

/*inserção no inicio*/
Lista2* lst2_insere(Lista2* l, int v){
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    if(l != NULL){
        l->ant = novo;
    }
    return novo;
}

/*função busca: busca um elemento na lista*/
Lista2* lst2_busca(Lista2* l, int v){
    Lista2* p;
    for(p = l; p != NULL; p=p->prox){
        if(p->info == v){
            return p;
        }
        return NULL; /*não achou o elemento*/
    }
}

/*função retira: retira um elemento da lista*/
Lista2* lst2_retira(Lista2* l, int v){
    Lista2* p = lst2_busca(l, v);

    if(p == NULL){
        return l;/*não achou o elemento*/
    }
    /*retira elemento do encadeamento*/
    if(l == p)/*testa se é o primeiro elemento*/{
        l = p->prox;
    }
    else{
        p->ant->prox == p->prox;
    }
    if(p->prox != NULL)/*testa se é o último elemento*/{
        p->prox->ant = p->ant;
    }
    free(p);
    return l;
}

void imprime(Lista2* l){
    Lista2 *count;
    for(count = l; count != NULL; count = count->prox){
        printf("%d ", count->info);
    }
}