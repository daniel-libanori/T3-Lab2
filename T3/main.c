#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void main(){

    Ponteiros prt;

    prt.arvPlac = NULL;
    prt.arvMarc = NULL;
    prt.arvAno  = NULL;
    prt.lstCar  = NULL;
    
    while ( interface(&prt) );

    


}