#include <stdio.h>

int main(void){

    float var = 2.5;
    
    //Declaração de ponteiro
    
    float *ponteiro;
    
    ponteiro = &var;

    printf("var = %f \n ponteiro = %p", var, ponteiro);

    //Modificar o valor da variável var atráves do ponteiro
    *ponteiro = 3.7;

    printf("\n Var = %f \n Ponteiro = %p", var, ponteiro);
    
    return 0;
}