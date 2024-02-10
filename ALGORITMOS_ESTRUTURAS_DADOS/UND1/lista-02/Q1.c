#include <stdio.h>

void realiza_troca(int *a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;

}

int main(void){
    int valor_1 = 1;
    int valor_2 = 2;
    printf("Valor a: %d - Valor b: %d",valor_1, valor_2);

    realiza_troca(&valor_1, &valor_2);
    
    printf("\nApos a troca:\n");
    printf("Valor a: %d - Valor b: %d",valor_1, valor_2);


    return 0;
}