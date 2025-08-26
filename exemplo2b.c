#include <stdio.h>
#include "exemplo2a.h"

int main(){
    printf("Exemplo 2\n");
    printf("Calculando 2x2 + y \n");
    int x = 2;
    int y = 3;
    float w = funcao1(x,y);
    printf("resultado : %f\n",w);
    return 0;
}