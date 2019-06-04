#ifndef FUNCOES_H
#define FUNCOES_H

    #include "struct.h"

    int interface(Ponteiros* prt);

    void arv_listar_ano (Arvore* a);
    void arv_listar_marca (Arvore* a);
    void listar_placa(Carro* lstPrinc);

    Arvore* arv_busca (Arvore* a, char placa[7]);
    Ponteiros* adicionar_carro(Ponteiros* prts);

    void limpa_tela();

#endif // !FUNCOES_H


