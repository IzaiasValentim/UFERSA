#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
	float raio,area;
	
	const float pi = 3.1415;
	
	printf("Informe o raio para c�lculo da circunfer�ncia: ...");
	scanf("%f",&raio);
	
	area = pi*pow(raio,2);
	
	printf("A �rea da circunfer�ncia �: %f",area);
	
	return 0;
}
