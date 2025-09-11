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

void pizzaToString(T_PIZZA *pizza, char *str){
    char retorno[100];
    sprintf(retorno,"%d;%s;%d",pizza->id,pizza->nome,pizza->preco);
    strncpy(str,retorno,strlen(retorno));
    return;
};

void stringToPizza(char *str, T_PIZZA *pizza){
    T_PIZZA *taux = (T_PIZZA *) malloc(sizeof(T_PIZZA));
    char *str2, *token;
    strcpy(str2, str);
    token = strtok(str2,";");
    for(int i = 0;i<3; i++ ){
        // campo id
        if (i == 0){
            int num = atoi(token); 
            taux->id = num;
        }
        // campo nome
        if (i == 1){
            strcpy(taux->nome, token);
        }
        // campo preco
        if (i == 2){
            int num = atoi(token);
            taux->preco = num;
        }
        token = strtok(NULL, ";");
    }
    *pizza = *taux;
    return;
};