#include <stdio.h>
#include <stdlib.h>



int main(void){

    int tamanho=0,i, *v;
    printf("Informe o tamanho do vetor a ser alocado: ");
    scanf("%d",&tamanho);

    v = (int *) malloc(tamanho*sizeof(int));
    printf("Informe os valores:");
    for(i=0;i<tamanho;i++){
        scanf("%d",v+i);
    }

    if(v == NULL){
        printf("\nErro ao alocar memoria");
        return 1;
    }

    int quant =0;
    for(i=0;i<tamanho;i++){
        if(v[i]%2 ==0){
            quant++;
        }
    }

    int pares = quant;
    int impares = tamanho-pares;
    
    printf("\nPares: %d\nImpares: %d",pares,impares);
    free(v);
    return 0;
}

