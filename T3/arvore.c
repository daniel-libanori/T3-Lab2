#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>


Arvore* arv_inserir_carro_placa(Arvore* a, Carro* c){

    if (a==NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->car = c;
        a->esq = a->dir = NULL;
    }

    else if (strcomp(c->placa, a->car->placa)<0)
        a->esq = abb_insere(a->esq,c);
    else
        a->dir = abb_insere(a->dir,c);
    
    return a;

}

Arvore* arv_inserir_carro_marca(Arvore* a, Carro* c){

    if (a==NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->car = c;
        a->esq = a->dir = NULL;
    }

    else if (strcomp(c->marca, a->car->marca)<0)
        a->esq = abb_insere(a->esq,c);
    else
        a->dir = abb_insere(a->dir,c);
    
    return a;

}

Arvore* arv_inserir_carro_ano(Arvore* a, Carro* c){

    if (a==NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->car = c;
        a->esq = a->dir = NULL;
    }

    else if (c->placa < a->car->placa)
        a->esq = abb_insere(a->esq,c);
    else
        a->dir = abb_insere(a->dir,c);
    
    return a;

}
