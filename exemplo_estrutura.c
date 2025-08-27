#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pizza {
    int id;
    int preco;
    char *nome;
};

struct pizza listapizza1[3];
struct pizza * listapizza2;

int size_listapizza1=0;
int size_listapizza2=0;

void printPizza(struct pizza p){
    printf("{ id: %d, nome: %s, preço: %d}\n",
        p.id, p.nome, p.preco);
}

void savePizza1(struct pizza p){
   listapizza1[size_listapizza1].id = p.id;
   listapizza1[size_listapizza1].preco = p.preco;
   strcpy(listapizza1[size_listapizza1].nome, p.nome);
   size_listapizza1++;
   return;
}

void loadPizza1(struct pizza *p, int id){
    if (id < size_listapizza1) {
        (*p).id = listapizza1[id].id;
        (*p).preco = listapizza1[id].preco;
        strcpy((*p).nome , listapizza1[id].nome);
    }
    return;
}

void savePizza2(struct pizza p){
   listapizza2[size_listapizza2].id = p.id;
   listapizza2[size_listapizza2].preco = p.preco;
   strcpy(listapizza2[size_listapizza2].nome, p.nome);
   size_listapizza2++;
   return;
}

void loadPizza2(struct pizza *p, int id){
    if (id < size_listapizza2) {
        (*p).id = listapizza2[id].id;
        (*p).preco = listapizza2[id].preco;
        strcpy((*p).nome , listapizza2[id].nome);
    }
    return;
}

int main(){
    printf("Exemplo estruturas \n");
    struct pizza p1;
    p1.id = 1;
    p1.preco = 50;
    p1.nome = "Napolitana";
    printPizza(p1);
    listapizza2 = (struct pizza *)malloc(sizeof(p1));
    savePizza1(p1);
    struct pizza p2 = {2,55,"Bolonhesa"};
    savePizza1(p2);

    for(int i=0; i <size_listapizza1; i++ ){
        printPizza(listapizza1[i]);
    }
    struct pizza p3;
    loadPizza1(&p3,0);
    return 0;
}