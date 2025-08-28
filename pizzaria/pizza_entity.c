#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pizza_entity.h"

void createPizza(int id, int preco, char *nome, T_PIZZA *pizza){
    T_PIZZA *taux = (T_PIZZA *) malloc(sizeof(T_PIZZA));
    taux->id = id;
    taux->preco = preco;
    strcpy(taux->nome , nome);
    *pizza = *taux;
    return;
};

void repricePizza(T_PIZZA *pizza, int preco){
    pizza->preco = preco;
    return;
};

void renamePizza( T_PIZZA *pizza, char *nome ){
    strcpy((*pizza).nome , nome);
    return;
};

void printPizza(T_PIZZA *pizza){
    printf("{ id: %d, nome: %s, preço: %d}\n",
        (*pizza).id, (*pizza).nome, (*pizza).preco);
    return;
};

void destroyPizza(T_PIZZA *pizza){
    if (pizza != NULL) 
        free(pizza);
    pizza = NULL;
};