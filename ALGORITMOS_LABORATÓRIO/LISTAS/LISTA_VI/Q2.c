#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int numerador, divisor;
	
	printf("Informe respectivamente o numerador e o divisor:\n ");
	
	scanf("%d\n",&numerador);
	
	scanf("%d",&divisor);
	
	if((numerador%divisor) == 0){
		
		printf("� divis�vel!");
		
	}else{
		
		printf("N�o � divis�vel!");
		
	}
	
	
	
	return 0;
}
