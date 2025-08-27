#include <stdio.h>

int main(){
    printf("Exemplo listas \n");
    // lista tamanho fixo
    printf("Lista int \n");
    int listafixaint[10] = {1,2,3,4,5,10,20,30,40,50};
    for (int i=0;i<10;i++) {
        printf("valor %d : %d \n", i, listafixaint[i]);
    }
    printf("Lista char \n");
    char listafixachar[11] = {  'H','e','l','l','o',' ','l','i','n','u','x'};
    for (int i=0;i<11;i++) {
        printf("valor %d : %c \n", i, listafixachar[i]);
    }
    
    return 0;
}