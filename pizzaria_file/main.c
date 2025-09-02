#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pizza_entity.h"
#include "pizza_repo.h"
#include "pizza_service.h"

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
    printf("Exemplo addPizza\n");
    listapizza = (T_PIZZA *)malloc(10*sizeof(T_PIZZA));
    addPizza(p1);
    
    T_PIZZA p2 = {2,55,"Bolonhesa"};
    addPizza(p2);
    
    printf("Exemplo listagem\n");
    for(int i=0; i <size_listapizza; i++ ){
        printPizza(&listapizza[i]);
    }
    printf("Exemplo getPizza\n");

    T_PIZZA p3;
    getPizza(&p3,1);
    printPizza(&p3);

    printf("Exemplo pizzaToString\n");
    char exemplo[255];
    pizzaToString(&p3,exemplo);
    printf("exemplo : %s\n",exemplo);

    printf("Exemplo stringToPizza\n");
    char *exemplo2 = "3;Margarita;80";
    stringToPizza(exemplo2,&p3);
    printPizza(&p3);
    addPizza(p3);

    printf("Exemplo savePizzaFile\n");
    savePizzaFile("milano.pizza");

    free(listapizza);
    listapizza = (T_PIZZA *)malloc(10*sizeof(T_PIZZA));
    printf("Exemplo loadPizzaFile\n");
    loadPizzaFile("roma.pizza");


    return 0;
}