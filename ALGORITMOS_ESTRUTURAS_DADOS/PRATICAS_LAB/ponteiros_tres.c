#include <stdio.h>

void incrementa( int * ponteiro){
    /*
    
        int * ponteiro para variável do tipo int;
        Realiza o incremento do contedo do ponteiro.
        
    */

    (*ponteiro)++;

}

int main(void){
    int var = 2;
    printf("var = %d\n", var);
    //&var enviar a localização na memória;
    incrementa(&var);
    printf("var = %d\n", var);
    return 0;
}