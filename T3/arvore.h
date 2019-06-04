#ifndef ARVORE_H
#define ARVORE_H

#include "struct.h"

    Arvore* arv_inserir_carro_placa(Arvore* a, Carro* c);
    Arvore* arv_inserir_carro_marca(Arvore* a, Carro* c);
    Arvore* arv_inserir_carro_ano(Arvore* a, Carro* c);

    Arvore* arv_retira (Arvore* a, char placa[7]);

#endif // !ARVORE_H



