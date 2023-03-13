#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
	float p1X,p1Y,p2X,p2Y,distancia;
	
	printf("Informe as coordenadas X e Y do primeiro ponto:\n");
	printf("X - ");
	scanf("%f",&p1X);
	printf("Y - ");
	scanf("%f",&p1Y);
	
	printf("Informe as coordenadas X e Y do segundo ponto:\n");
	printf("X - ");
	scanf("%f",&p2X);
	printf("Y - ");
	scanf("%f",&p2Y);
	
	float dentro = pow((p2X-p1X),2) + pow((p2Y-p1Y),2);
	
	distancia = pow(dentro,0.5);
	
	printf("A distância entre dois pontos é aproximadamente: %.1f",distancia);
	
	return 0;
}
