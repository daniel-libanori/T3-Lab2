#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "struct.h"
#include "lista.h"
#include "arvore.h"


Ponteiros* adicionar_carro(Ponteiros* prts){

        int ano;
        char placa[7];
        char marca[20];
        Carro* c;
        
        printf("Digite a placa do Carro (3 letras maiusculas e 4 numeros, sem espaço entre eles): ");
        scanf("%s", placa);
        if(verificar_se_placa_ja_existe(prts->lstCar,placa)){
                printf("Ja existe um carro com essa placa, tente novamente.");
                return prts;
        }
        printf("Digite a marca do Carro: ");
        scanf("%s", marca);
        printf("Digite o ano do Carro: ");
        scanf("%d", &ano);
        prts->lstCar = adicionar_lista_ord(prts->lstCar,ano,placa,marca);
        c = busca_carro_lista(prts->lstCar,placa);

        arv_inserir_carro_ano(prts->arvAno,c);
        arv_inserir_carro_marca(prts->arvMarc,c);
        arv_inserir_carro_placa(prts->arvPlac,c);

        return prts;

}

Arvore* abb_busca (Arvore* a, char placa[7]){
        
        if (a == NULL)
                return NULL;
        
        else if (strcomp(a->car->placa, placa) > 0)
                return abb_busca (a->esq, placa);
        
        else if (strcomp(a->car->placa, placa) < 0)
                return abb_busca (a->dir, placa);
        
        else
                return a;
}

void listar_placa(Carro* lstPrinc){

        Carro* c;

        printf("\tAno \t Placa \t     Marca\n",c->ano,c->placa,c->marca);

        for(c=lstPrinc; c!=NULL; c=c->prox){
                printf("\t%.4d\t%s\t%.20s\n",c->ano,c->placa,c->marca);
        }

}

void arv_listar_marca (Arvore* a){

        if (a != NULL) {
                arv_listar_marca(a->esq);
                printf("%s\n",a->car->marca);
                arv_listar_marca(a->dir);
        }

}

void arv_listar_ano (Arvore* a){

        if (a != NULL) {
                arv_listar_ano(a->esq);
                printf("%d\n",a->car->ano);
                arv_listar_ano(a->dir);
        }
        
}

int interface(Ponteiros* prts){

    int acao;

    printf("\n\tEscolha a acao desejada:\n");
    printf("\n\t 1 - Adicionar Carro");
    printf("\n\t 2 - Excluir Carro");
    printf("\n\t 3 - Buscar Carro pela Placa");
    printf("\n\t 4 - Listar Carros pela Placa");
    printf("\n\t 5 - Listar Carros pela Marca");
    printf("\n\t 6 - Listar Carros pelo Ano");
    printf("\n\t 0 - Sair");

    acao = getch() - 48 ;

    switch (acao){
    case 1: //Adicionar Carro ((OK))
            break;
    case 2: //Excluir Carro
            break;
    case 3: //Buscar Carro pela Placa - Arvore ((OK))
            break;
    case 4: //Listar Carros pela Placa ((OK))
            break;
    case 5: //Listar Carros pela Marca ((OK))
            break;
    case 6: //Listar Carros pelo Ano ((OK))
            break;

    case 0: return 0;
            break;
    default://Digite Uma opcao valida
            break;
    }

    return 1;


}