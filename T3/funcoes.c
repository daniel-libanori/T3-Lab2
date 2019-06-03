#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "struct.h"


Ponteiros* adicionar_carro(Ponteiros* prts){





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
    case 1: //Adicionar Carro
            break;
    case 2: //Excluir Carro
            break;
    case 3: //Buscar Carro pela Placa
            break;
    case 4: //Listar Carros pela Placa
            break;
    case 5: //Listar Carros pela Marca
            break;
    case 6: //Listar Carros pelo Ano
            break;

    case 0: return 0;
            break;
    default://Digite Uma opcao valida
            break;
    }

    return 1;


}