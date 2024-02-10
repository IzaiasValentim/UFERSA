#include <stdio.h>

#define T 10

// Protótipo da função.
void MinMax(int numeros[T], int *min, int *max );

int main(void){

    // Vetor de inteiros de tamanho T.
    int valores[T] ={1,1,2,3,0,5,6,90,8,40};

    // Inicialização/declaração das variáveis inteiras para o valor minímo, máximo e contador(i).
    int min =0;
    int max = 0;
    int i;
    // Chamada da função.
    MinMax(valores, &min, &max);

    //Formatação da saída.
    printf("Valores: [");
    for(i=0;i<T; i++){
        printf(" %d",valores[i]);
    }
    printf("]\n");
    printf("Menor valor: %d - Maior valor: %d",min, max);
    //Esperado: Menor valor: 0 - Maior valor: 90
    return 0;
}

void MinMax(int numeros[T], int *min, int *max ){
    int i;
    
    // Inicialização do min e max pela base do vetor de números.
    *min = numeros[0];
    *max = numeros[0];

    for(i=0;i<T;i++){
        // A cada iteração, verifica se o inteiro da posição atual é menor que o base,
        // Caso seja, o valor será atualizado em *min.
        if (numeros[i] <= *min){
            *min = numeros[i];
        }

        // A cada iteração, verifica se o inteiro da posição atual é maior que o base,
        // Caso seja, o valor será atualizado em *max.
        if(numeros[i]>=*max){
            *max = numeros[i];
        }
    }
}