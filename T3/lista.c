#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


int verificar_se_placa_ja_existe(Carro* lstPrinc, Carro* novo){

    Carro* c;

    for(c=lstPrinc; c!=NULL;c=c->prox){
        if(strcomp(novo->placa,c->placa)==0){
            return 1;
        }
    }

    return 0;


}





Carro* adicionar_lista_ord(Carro* lstPrinc, Carro* novo){

    Carro* c;

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