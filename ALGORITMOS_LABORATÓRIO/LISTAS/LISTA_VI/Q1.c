#include <stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	float numero;
	
	printf("Informe um n�mero: ");
	scanf("%f",&numero);
	
		if(numero == 0.0){
			
			printf("O n�mero � neutro");
			
		}else if(numero < 0){
			
			printf("O n�mero � negativo");
			
		}else if(numero > 0){
			
			printf("O n�mero � positivo");
			
		}
	
	
	
	
	return 0;
}
