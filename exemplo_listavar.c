#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Exemplo listas \n");
    // lista tamanho fixo
    printf("Lista int \n");
    int *listaint;
    int x = 0;
    int sizeint = sizeof(x);
    listaint = (int *)malloc(10 * sizeint);
    // grava memoria
    for (int i=0;i < 10 ; i++) {
        listaint[i]=(i +1)*5;
    }
    // lee memoria
    for (int i=0;i < 10 ; i++) {
        printf("valor %d : %d \n", i, listaint[i]);
    }

    // lee memoria otra forma
    for (int i=0;i < 10 ; i++) {
        printf("valor %d : %d \n", i, *(listaint + i));
    }

    printf("Lista char 1\n");
    char *listachar="Hello Linux";
    for (int i=0;i<sizeof(listachar);i++) {
        printf("valor %d : %c \n", i, listachar[i]);
    }
    printf ("valor s : %s \n",listachar);
    printf("Lista char 2\n");
    for (int i=0;i<strlen(listachar);i++) {
        printf("valor %d : %c \n", i, listachar[i]);
    }
    printf ("valor s : %s \n",listachar);

    listachar = "is Fun";
    for (int i=0;i<strlen(listachar);i++) {
        printf("valor %d : %c \n", i, listachar[i]);
    }
    printf ("valor s : %s \n",listachar);

    char * otralista = (char *) malloc(11);
    strncpy(otralista,listachar,10);
    printf ("valor s : %s \n",otralista);



    return 0;
}