#include <stdio.h>

void printTail(int n)
{
    if(n>0){
        printf("%d ",n);  
        print(n-1);
    }
    
}

void printNonTail(int n)
{
    if(n>0){
        print(n-1);
        printf("%d ",n);   
    }
    
}

int main()
{
    int n = 6;

    // Chamada da funcao print
    printTail(n);
    return 0;
}