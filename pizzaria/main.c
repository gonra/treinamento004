#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pizza_repo.h"

extern T_PIZZA *listapizza;
extern int size_listapizza;

int main(){
    printf("Exemplo estruturas \n");
    T_PIZZA p1;
    // cria pizza
    createPizza(1,50,"Napolitana",&p1);
    printPizza(&p1);
    // alterando pizza
    repricePizza(&p1, 60);
    renamePizza(&p1, "Havaiana");
    printPizza(&p1);
    printf("Exemplo savePizza\n");
    listapizza = (T_PIZZA *)malloc(10*sizeof(p1));
    setPizza(p1);
    
    T_PIZZA p2 = {2,55,"Bolonhesa"};
    setPizza(p2);
    
    printf("Exemplo listagem\n");
    for(int i=0; i <size_listapizza; i++ ){
        printPizza(&listapizza[i]);
    }

    printf("Exemplo loadPizza\n");
    T_PIZZA p3;
    getPizza(&p3,1);
    printPizza(&p3);
    return 0;
}