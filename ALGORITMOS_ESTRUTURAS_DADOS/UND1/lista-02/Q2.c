#include<stdio.h>
#define T 10

int main(void){

    int numeros[T] ={1,2,3,4,5,6,7,8,9,10};
    int i;
    printf("Posicoes:");
    for(i=0;i<T;i++){
        printf("\n%p", &numeros[i]);
    }
}