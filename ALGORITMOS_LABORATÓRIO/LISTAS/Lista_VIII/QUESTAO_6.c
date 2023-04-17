#include<stdio.h>
#include<locale.h>

float area_circ(float raio);
const float PI = 3.14;

int main(){
	setlocale(LC_ALL,"Portuguese");
	float raio,area;
	printf("--Cálculoa circunferência--\n");
	printf("--Qual o raio do circulo?--\n");
	scanf("%f",&raio);
	
	area = area_circ(raio);
	
	printf("A área da circunferência(UA): %.2f",area);
	
	return 0;
}

float area_circ(float raio){
	
	float area = PI*(raio*raio);
	
	return (area);
	
}
