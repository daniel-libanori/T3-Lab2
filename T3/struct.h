#ifndef STRUCT_H
#define STRUCT_H


    typedef struct carro{

        char placa[7];
        int ano;
        char marca[20];
        struct carro* prox;

    } Carro;


    typedef struct arvore{

        struct carro* car;
        struct arvore* esq;
        struct arvore* dir;

    } Arvore;

    typedef struct ponteiros{

        struct arvore* arvPlac;
        struct arvore* arvMarc;
        struct arvore* arvAno;
        struct carro*  lstCar;

    } Ponteiros;


#endif 