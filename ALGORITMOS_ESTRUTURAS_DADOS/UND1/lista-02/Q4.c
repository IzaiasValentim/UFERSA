#include <stdio.h>

// Protótipo da função.
int SomaDoDobro(int *A, int *B);

int main(){
    
    // Declaração e leitura dos valores a,b.
    int a,b;
    printf("Informe dois numeros: \n");
    scanf("%d",&a);
    scanf("%d",&b);

    // Chamada da função.
    int resultado = SomaDoDobro(&a, &b);

    // Saída com os resultados.
    printf("\nDobro de A: %d", a);
    printf("\nDobro de B: %d", b);
    printf("\nA soma do dobro dos numeros e: %d",resultado);

    return 0;
}

int SomaDoDobro(int *A, int *B){
    // O dobro dos números calculado nas próprias variáveis.
    *A *= 2;
    *B *= 2;

    return (*A+*B);
}