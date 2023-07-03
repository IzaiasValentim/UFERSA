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

    *area = (3*pow(l,2)*sqrt(3))/2;
    *perimetro = 6 * l;

}