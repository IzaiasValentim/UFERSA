#include<stdio.h>
#include<math.h>
int main(){
	float numero =0;
	
	printf("Informe um n�mero: ");
	scanf("%f",&numero);
	
	printf("O cubo de %.1f �: %.1f",numero,pow(numero,3));
	
	return 0;
}
