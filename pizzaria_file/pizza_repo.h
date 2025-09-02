#ifndef __PIZZA_REPO_H
#define __PIZZA_REPO_H

#include "pizza_entity.h"

void addPizza(T_PIZZA p);
void getPizza(T_PIZZA *p, int id);
void cleanPizza();

#endif