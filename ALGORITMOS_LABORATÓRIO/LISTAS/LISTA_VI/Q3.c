#include <stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	float numeroA, numeroB,operacao;
	char opc = ' ';
	
	printf("###--Calculadora em C!--###\n");
	printf("# Informe os dois numeros #\n");
	printf("# Operações: + - x /      #\n");
	
	scanf("%f",&numeroA);
	scanf("%f",&numeroB);
	printf("#Informe uma operação:    #\n");
	scanf("%s",&opc);
	
	
	switch(opc){
		
		case '+':
			operacao = numeroA+numeroB;	
			break;
		
		case '-':
			operacao = numeroA-numeroB;	
			break;
		
		case 'x':
			operacao = numeroA*numeroB;	
			break;
			
		case '/':
			
			if(numeroB != 0){
			
				operacao = numeroA/numeroB;	
			
			}else{
				
				printf("Divisão indefinida!");
				return 1;
			}
			
			break;
			
		default:
				printf("Informe uma opção válida!");
	}
	
	printf("#R: %f %c %f = %f      #",numeroA,opc,numeroB,operacao);
	
	
	return 0;
}
