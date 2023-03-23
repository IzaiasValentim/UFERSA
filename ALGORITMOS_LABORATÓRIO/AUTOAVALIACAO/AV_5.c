#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	float altura, peso, imc;
	
	printf("Informe respectivamente o seu peso e sua altura para o cálculo do imc: ");
	
	scanf("%f",&peso);
	scanf("%f",&altura);
	
	if(peso > 0 && altura > 0){
		
		imc = peso/pow(altura,2);
		
	}else{
		printf("Entradas inválidas!");
		return 1;
	}
	
	if(imc < 18.5){
		
		printf("O seu imc é: %.2f - Classificação: Magreza",imc);
		
	}else if(imc >=18.5 && imc <24.9){
	
		printf("O seu imc é: %.2f - Classificação: Saudável",imc);	
	
	}else if(imc >= 25 && 	imc < 29.9){
		
		printf("O seu imc é: %.2f - Classificação: Sobrepeso",imc);

	}else if(imc >= 30 && imc < 34.9 ){
		printf("O seu imc é: %.2f - Classificação: Obesidade Grau I",imc);

	}else if(imc >= 35 && imc < 39.9 ){
		
		printf("O seu imc é: %.2f - Classificação: Obesidade Grau II(Severa)",imc);
	
	}else if(imc >= 40){
		printf("O seu imc é: %.2f - Classificação: Obesidade Grau III(mórbida)",imc);
	}	
	
	
	return 0;
}
