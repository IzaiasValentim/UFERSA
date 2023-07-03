#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro);

int main(void){
    
    float lado, area, perimetro;

    
    printf("Informe o lado do hexágono regular: \n");
    scanf("%f",&lado);
    
    calcula_hexagono(lado, &area, &perimetro);
    
    printf("O hexagono regular de l = %.2f terá A = %.2f U.A e P = %.2f U.P",lado,area,perimetro);

    return 0;
}

void calcula_hexagono(float l, float *area, float *perimetro){
    
    /*
        Função que calcula a área e perímetro de um hexágono regular.

        float l : lado, valor decimal.
        float *area: ponteiro do tipo real.
        float *perimetro: ponteiro do tipo real.    

        Entrada: lado(fornecido pelo usuário), endereço para area, endereço para o perímetro.

        ação: cálculo da área é armazenado no endereço do ponteiro da area.
              cálculo da perimetro é armazenado no endereço do ponteiro do perimetro.
             
    */  
   
    *area = (3*pow(l,2)*sqrt(3))/2;
    *perimetro = 6 * l;

}