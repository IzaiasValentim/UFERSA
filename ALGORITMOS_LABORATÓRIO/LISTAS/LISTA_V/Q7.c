#include<stdio.h>
#include<math.h>
int main(){
	float numero =0;
	
	printf("Informe um número: ");
	scanf("%f",&numero);
	
	printf("O cubo de %.1f é: %.1f",numero,pow(numero,3));
	
	return 0;
}
