#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	float tc,tf;
	printf("Informe a temperatura em Fahrenheit:...");
	scanf("%f",&tf);
	
	tc = (tf -32)/1.8;
	printf("%.1fF em celcius: %.1f",tf,tc);
	
	return 0;
}
