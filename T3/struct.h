#ifndef STRUCT_H
#define STRUCT_H


typedef struct ponteiros{

    Arvore* arvPlac;
    Arvore* arvMarc;
    Arvore* arvAno;
    Carro*  lstCar;


}Ponteiros;


typedef struct carro{

    char placa[7];
    int ano;
    char marca[20];
    Carro* prox;

}Carro;


typedef struct arvore{

    Carro* car;
    Arvore* esq;
    Arvore* dir;

}Arvore;


#endif 