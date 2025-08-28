#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pizza_repo.h"

T_PIZZA * listapizza;

int size_listapizza=0;

void savePizza(T_PIZZA p){
   listapizza[size_listapizza].id = p.id;
   listapizza[size_listapizza].preco = p.preco;
   strcpy(listapizza[size_listapizza].nome, p.nome);
   size_listapizza++;
   return;
}

void loadPizza(T_PIZZA *p, int id){
    if (id < size_listapizza) {
        (*p).id = listapizza[id].id;
        (*p).preco = listapizza[id].preco;
        strcpy((*p).nome , listapizza[id].nome);
    }
    return;
}