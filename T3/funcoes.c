#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "struct.h"
#include "lista.h"
#include "arvore.h"

void limpa_tela(){
        system("cls");
}


Ponteiros* remover_carro(Ponteiros* prts){

        char placa[7];

        printf("Digite a placa do Carro de deseja excluir: ");
        fgets(placa,7,stdin);

        if(busca_carro_lista(prts->lstCar,placa)==NULL){
                printf("Carro nao existente");
                return prts;
        }

        arv_retira(prts->arvAno,placa);
        arv_retira(prts->arvPlac,placa);
        arv_retira(prts->arvMarc,placa);

        retirar_lista(prts->lstCar,placa);

        return prts;

}


Ponteiros* adicionar_carro(Ponteiros* prts){

        int ano;
        char placa[7];
        char marca[20];
        Carro* c;


        fflush(stdin);
        printf("\n\tDigite a placa do Carro (3 letras maiusculas e 4 numeros, sem espaco entre eles): ");
        //scanf("%s", placa);
        fgets(placa,7,stdin);
        fflush(stdin);
        if(verificar_se_placa_ja_existe(prts->lstCar,placa)){
                printf("\n\tJa existe um carro com essa placa, tente novamente.");
                return prts;
        }
        
        printf("\n\tDigite a marca do Carro: ");
        //scanf("%s", marca);
        fgets(marca,20,stdin);
        fflush(stdin);

        printf("\n\tDigite o ano do Carro: ");
        scanf("%d", &ano);
        fflush(stdin);
        prts->lstCar = adicionar_lista_ord(prts->lstCar,ano,placa,marca);
        c = busca_carro_lista(prts->lstCar,placa);

        prts->arvAno  = arv_inserir_carro_ano(prts->arvAno,c);
        prts->arvMarc = arv_inserir_carro_marca(prts->arvMarc,c);
        prts->arvPlac = arv_inserir_carro_placa(prts->arvPlac,c);

        return prts;

}

Arvore* arv_busca (Arvore* a, char placa[7]){
        printf("okk");
        if (a == NULL)
                return NULL;
        
        else if (strcmp(a->car->placa, placa) > 0)
                return arv_busca (a->esq, placa);
        
        else if (strcmp(a->car->placa, placa) < 0)
                return arv_busca (a->dir, placa);
        
        else
                return a;
}

void listar_placa(Carro* lstPrinc){

        Carro* c;

        printf("\n\tAno \t Placa \t     Marca\n",c->ano,c->placa,c->marca);

        for(c=lstPrinc; c!=NULL; c=c->prox){
                printf("\t%d\t%s\t%s\n",c->ano,c->placa,c->marca);
        }

}

void arv_listar_marca (Arvore* a){

        if (a != NULL) {
                arv_listar_marca(a->esq);
                printf("\n\tMarca: %s\tPlaca%s\tAno:%d\n", a->car->marca,a->car->placa, a->car->ano);
                printf("%s\n",a->car->marca);
                arv_listar_marca(a->dir);
        }

}

void arv_listar_ano (Arvore* a){

        if (a != NULL) {
                arv_listar_ano(a->esq);
                printf("\n\tAno: %d\tPlaca%s\tMarca:%s\n",a->car->ano,a->car->placa,a->car->marca);
                arv_listar_ano(a->dir);
        }
        
}

int interface(Ponteiros* prts){

        int acao;
        char placa[7];
        Arvore* arvTemp;

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
    case 1: prts = adicionar_carro(prts);
            break;
    case 2: remover_carro(prts);
            break;
    case 3: 
        printf("\n\n\tDigite a Placa para buscar: ");
        scanf("%s", placa);
        arvTemp = arv_busca(prts->arvPlac, placa);
        printf("\n\tPlaca: %s\n\tMarca: %s\n\tAno: %d", arvTemp->car->placa, arvTemp->car->marca, arvTemp->car->ano);
        break;
    
    case 4: listar_placa(prts->lstCar);
            break;
    case 5: arv_listar_marca(prts->arvMarc);
            break;
    case 6: arv_listar_ano(prts->arvAno);
            break;

    case 0: return 0;
            break;
    default://Digite Uma opcao valida
            break;
    }

    return 1;


}