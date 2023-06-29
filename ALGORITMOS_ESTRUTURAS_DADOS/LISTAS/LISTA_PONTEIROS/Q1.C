#include <stdio.h>

int main(void){

    /** Quais serão os valores de x, y e p ao final
        do trecho de código.
    **/
   int x,y, *p;
    y = 0; // y = 0;
    p = &y; // ponteiro recebe o valor presente no espaço de memoria de y;
    x = *p; // x = 0;
    x = 4;  // x = 4;
    (*p)++; // *p = *p +1 >> p =1, y = 1;
    --x;    // x = 3;
    (*p) += x; // (*p) = 3 + 1 > (*p) = 4;

    
    printf("x = %d, y = %d, p = %d",x,y,*p);
    //x = 3, y = 4, p =4;
    return 0;
}