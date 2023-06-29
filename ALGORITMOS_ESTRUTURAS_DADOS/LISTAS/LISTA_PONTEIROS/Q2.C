#include <stdio.h>

int main(void) {
    int x, *p;
    x = 100;
    p = &x;

    printf("Valor de p =%p \tValor de *p = %d",p,*p);
    /*  
    -Sim, fornecerá alguma mensagem.
    
    -a) Uma mensagem de erro.
    -b) Devido ao fato de estarmos tentando aplicar um endereço da memória a um ponteiro sem o operador de endereço da variável.
    -c) Não,
    -d) Adicionei o operador de endereço(&) à variável x.
    -e) Sim.
    */
    return 0;
}