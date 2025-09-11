#ifndef __PIZZA_REPO_H
#define __PIZZA_REPO_H

#include "pizza_entity.h"

void addPizza(T_PIZZA p);
void getPizza(T_PIZZA *p, int id);
int  initPizzaDB();
int closePizzaDB();
int  insertPizzaDB(T_PIZZA *p);
int  loadPizzaById(T_PIZZA *p, int id);
void cleanPizza();

#endif