#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


int verificar_se_placa_ja_existe(Carro* lstPrinc, char placa[7]){

    Carro* c;

    for(c=lstPrinc; c!=NULL;c=c->prox){
        if(strcomp(placa,c->placa)==0){
            return 1;
        }
    }

    return 0;


}

Carro* adicionar_lista_ord(Carro* lstPrinc, int ano, char placa[7], char marca[20]){

    Carro* c;
    Carro* novo = (Carro*)malloc(sizeof(Carro));
    novo->ano = ano;
    strcpy(novo->placa,placa);
    strcpy(novo->marca,marca);


    if(lstPrinc == NULL){
        novo->prox = NULL;
        lstPrinc = novo;
        return lstPrinc;
    }

    if(strcomp(novo->placa,lstPrinc->placa)>0){
        novo->prox = lstPrinc;
        lstPrinc = novo;
        return lstPrinc;
    }

    for(c=lstPrinc; c!=NULL; c=c->prox){
        if(strcomp(novo->placa,c->prox->placa)>0){
            novo->prox = c->prox;
            c->prox = novo;
            return lstPrinc;
        }
    }



}


Carro* busca_carro_lista(Carro* lstPrinc, char placa[7]){

    Carro* c;

    for(c=lstPrinc;c!=NULL;c=c->prox){
        if(strcomp(placa,c->placa)==0){
            return c;
        }
    }

    return NULL;


}