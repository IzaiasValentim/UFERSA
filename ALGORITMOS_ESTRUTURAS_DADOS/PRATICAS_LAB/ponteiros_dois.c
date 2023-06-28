#include <stdio.h>

int main(void){

    float var = 2.5;
    float *ponteiro;
    ponteiro = &var;

printf("var = %f \n ponteiro = %p", var, ponteiro);

    return 0;
}