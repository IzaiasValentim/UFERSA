#include <stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	float numero;
	
	printf("Informe um número: ");
	scanf("%f",&numero);
	
		if(numero == 0.0){
			
			printf("O número é neutro");
			
		}else if(numero < 0){
			
			printf("O número é negativo");
			
		}else if(numero > 0){
			
			printf("O número é positivo");
			
		}
	
	
	
	
	return 0;
}
