#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");	
	
	float cotacaoD,valorReais,valorDolar;
	
	printf("Informe a cota��o atual do dolar: ...\n");
	scanf("%f",&cotacaoD);
	
	printf("Informa a quantidada de reais a ser convertida para dolar: ...\n");
	scanf("%f",&valorReais);
	
	valorDolar = valorReais/cotacaoD;
	
	printf("%.1f reais em d�rales ser�: %.1f",valorReais,valorDolar);	
	return 0;
}
