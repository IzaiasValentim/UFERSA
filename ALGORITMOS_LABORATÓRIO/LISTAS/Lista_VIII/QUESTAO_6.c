#include<stdio.h>
#include<locale.h>

float area_circ(float raio);
const float PI = 3.14;

int main(){
	setlocale(LC_ALL,"Portuguese");
	float raio,area;
	printf("--C�lculoa circunfer�ncia--\n");
	printf("--Qual o raio do circulo?--\n");
	scanf("%f",&raio);
	
	area = area_circ(raio);
	
	printf("A �rea da circunfer�ncia(UA): %.2f",area);
	
	return 0;
}

float area_circ(float raio){
	
	float area = PI*(raio*raio);
	
	return (area);
	
}
