

typedef struct carro Carro;
typedef struct arvore Arvore;
typedef struct ponteiros Ponteiros;

struct carro{

    char placa[7];
    int ano;
    char marca[20];
    Carro* prox;

};


struct arvore{

    Carro* car;
    Arvore* esq;
    Arvore* dir;

};

struct ponteiros{

    Arvore* arvPlac;
    Arvore* arvMarc;
    Arvore* arvAno;
    Carro*  lstCar;

};