#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pizza {
    int id;
    int preco;
    char nome[30];
};

typedef struct pizza T_PIZZA;

T_PIZZA * listapizza;

int size_listapizza=0;

void printPizza(T_PIZZA p){
    printf("{ id: %d, nome: %s, preço: %d}\n",
        p.id, p.nome, p.preco);
}

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

int main(){
    printf("Exemplo estruturas \n");
    T_PIZZA p1;
    p1.id = 1;
    p1.preco = 50;
    strcpy(p1.nome, "Napolitana");
    printf("Exemplo 1 savePizza\n");
    printPizza(p1);
    listapizza = (T_PIZZA *)malloc(sizeof(p1));
    savePizza(p1);
    T_PIZZA p2 = {2,55,"Bolonhesa"};
    savePizza(p2);
    printf("Exemplo 2 listagem\n");
    for(int i=0; i <size_listapizza; i++ ){
        printPizza(listapizza[i]);
    }

    printf("Exemplo 3 loadPizza\n");
    T_PIZZA p3;
    loadPizza(&p3,1);
    printPizza(p3);
    return 0;
}