#include <stdio.h>

int main(void){

    int a,b,c,d; //Declarações
    
    int *p1; //---
    
    int *p2 = &a; // p2 recebe a posição da memoria da váriavel(a);
    
    int *p3 = &c; // p3 recebe a posição da memória da variável (c);
    
    p1 = p2; // p1 = p2 = &a;
    
    *p2 = 10; // a = 10, *p1 = 10, *p2 = 10;
    
    b =20; // b = 20;
    
    int **pp; // declaração

    pp = &p1; // pp recebe o endereço de p1 na memória.

    *p3 = **pp; // *p3 recebe o valor presente no **pp que é o valor presente o valor presente em *p1; 
                // *p3 = 10;

    int *p4 = &d; 
    
    *p4 = b + (*p1)++; 
    //Devido as prioridades(esq -> dir), b + (*p1) será somado, para só após o incremento ser realizado em *p1.

    printf("%d\t%d\t%d\t%d\n", a, b, c, d);
    //a = 11; b = 20; c = 10; d = 30
    return 0;
}