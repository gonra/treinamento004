#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#include "pizza_entity.h"
#include "pizza_repo.h"

extern T_PIZZA *listapizza;
extern int size_listapizza;

extern  sqlite3 *db;

int main(){
 
    T_PIZZA p1;

    initPizzaDB();

    createPizza(10,30,"Havaiana",&p1);

    printPizza(&p1);
    
    insertPizzaDB(&p1);

    int nextid = selectNextIdPizzaDB();

    closePizzaDB();

    return 0;
}