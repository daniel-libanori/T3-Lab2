#ifndef LISTA_H
#define LISTA_H

    #include "struct.h"

    Carro* busca_carro_lista(Carro* lstPrinc, char placa[7]);
    Carro* adicionar_lista_ord(Carro* lstPrinc, int ano, char placa[7], char marca[20]);
    
    int verificar_se_placa_ja_existe(Carro* lstPrinc, char placa[7]);
    Carro* retirar_lista(Carro* lstPrinc, char placa[7]);




#endif


