#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

Arvore* arv_retira (Arvore* a, char placa[7]){

    if (a == NULL)
        return NULL;
    else if (strcmp(a->car->placa, placa)>0)
        a->esq = arv_retira(a->esq, placa);
    else if (strcmp(a->car->placa, placa)<0)
        a->dir = arv_retira(a->dir, placa);

    else { /* achou o nó a remover */
        
        /* nó sem filhos */
        if (a->esq == NULL && a->dir == NULL) {
            //free(a->car);
            free (a);
            a = NULL;
        }
        /* nó só tem filho à direita */
        else if (a->esq == NULL) {
            Arvore* t = a;
            a = a->dir;
            //free(t->car);
            free (t);
        }
        /* só tem filho à esquerda */
        else if (a->dir == NULL) {
            Arvore* t = a;
            a = a->esq;
            //free(t->car);
            free (t);
        }
        /* nó tem os dois filhos */
        else {
            Arvore* f = a->esq;
            while (f->dir != NULL) {
                f = f->dir;
            }

            strcpy(a->car->placa,f->car->placa);
            strcpy(f->car->placa, placa);
            a->esq = arv_retira(a->esq,placa);
        }

    }
    return a;
}

Arvore* arv_inserir_carro_placa(Arvore* a, Carro* c){

    if (a==NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->car = c;
        a->esq = a->dir = NULL;
    }

    else if (strcmp(c->placa, a->car->placa)<0)
        a->esq = arv_inserir_carro_placa(a->esq,c);
    else
        a->dir = arv_inserir_carro_placa(a->dir,c);
    
    return a;

}

Arvore* arv_inserir_carro_marca(Arvore* a, Carro* c){

    if (a==NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->car = c;
        a->esq = a->dir = NULL;
    }

    else if (strcmp(c->marca, a->car->marca)<0)
        a->esq = arv_inserir_carro_marca(a->esq,c);
    else
        a->dir = arv_inserir_carro_marca(a->dir,c);
    
    return a;

}

Arvore* arv_inserir_carro_ano(Arvore* a, Carro* c){
    
    if (a==NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->car = c;
        a->esq = a->dir = NULL;
    }

    else if (c->placa < a->car->placa)
        a->esq = arv_inserir_carro_ano(a->esq,c);
    else
        a->dir = arv_inserir_carro_ano(a->dir,c);
    
    return a;

}
