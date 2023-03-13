#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
	float raio,area;
	
	const float pi = 3.1415;
	
	printf("Informe o raio para cálculo da circunferência: ...");
	scanf("%f",&raio);
	
	area = pi*pow(raio,2);
	
	printf("A área da circunferência é: %f",area);
	
	return 0;
}
