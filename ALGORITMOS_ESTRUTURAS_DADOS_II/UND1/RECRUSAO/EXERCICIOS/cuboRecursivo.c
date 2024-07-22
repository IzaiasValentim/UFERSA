#include <stdio.h>

/*
    Escrever uma versão recursiva da função abaixo:

    void cubos (int n ){
        for (int i =1; i <= n ; i ++){
        printf ("%d", i * i * i );
        }
    }
 */

void printEach(int n){
    if(n >= 1){
        printEach(n-1);
        printf("%d ",n*n*n);
    }
}

int main(){
    printEach(4);
    return 0;
}