#include <stdio.h>

int fun1(int a, int b) {
    a = a * 3;
    return (a + 2 *b);
}

int fun2(int *a, int b) {
    *a = (*a) * 3;
    return ((*a) + 2 * b);
}

void fun3(int a, int b, int * res) {
    *res = 4*a + 3*b;
    return;
}

int main(){

    printf("Exemplo funcoes \n");
    printf("Funcao por valor\n");
    int x = 10;
    int y = 20;
    

    int res1 = fun1(x,y);

    printf("Valor fun1 x=%d , y=%d, res1=%d \n",x,y,res1);

    printf("Funcao por referencia1\n");

    int res2 = fun2(&x, y);

    printf("Valor fun1 x=%d , y=%d, res1=%d \n",x,y,res2);

    printf("Funcao por referencia2\n");
    int res3 = 0;
    fun3(x, y, &res3);

    printf("Valor fun3 x=%d , y=%d, res3=%d \n",x,y,res3);


    return 0;
}