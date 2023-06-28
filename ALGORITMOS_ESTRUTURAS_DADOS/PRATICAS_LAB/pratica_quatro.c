#include <stdio.h>

int soma(int valor1, int valor2){
    /*
        Função que soma dois valores
        int valor1: valor inteiro
        int valor2: valor inteiro


    */
   int sum = valor1+valor2;
   return sum;
}


int main(void){

    int (*f)(int,int) = soma;

    int resultado = f(1,1);

    printf("soma = %d, p = %p \n",resultado,f);

    return 0;
}