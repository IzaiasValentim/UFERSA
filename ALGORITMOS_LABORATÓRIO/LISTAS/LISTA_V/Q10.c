#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	float peso,altura,imc;
	printf("#-- Cálculo do IMC --#");
	printf("Informe a sua altura e peso: ...");
	scanf("%f%f",&altura,&peso);
	
	imc = peso/pow(altura,2);
	
	printf("Seu IMC é: %f",imc);
	
	
	return 0;
}
