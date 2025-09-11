#ifndef __PIZZA_ENTITY_H
#define __PIZZA_ENTITY_H


struct pizza {
    int id;
    int preco;
    char nome[30];
};

typedef struct pizza T_PIZZA;

void createPizza(int id, int preco, char *nome, T_PIZZA *pizza);
void repricePizza(T_PIZZA *pizza, int preco);
void renamePizza( T_PIZZA *pizza, char *nome );
void printPizza(T_PIZZA *pizza);
void destroyPizza(T_PIZZA *pizza);

void pizzaToString(T_PIZZA *pizza, char *str);
void stringToPizza(char *str, T_PIZZA *pizza);

#endif