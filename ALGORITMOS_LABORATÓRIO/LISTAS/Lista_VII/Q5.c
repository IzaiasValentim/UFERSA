#include <stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	float notaUm,notaDois,notaTres,media = 0;
	int i;
	
	for(i=0;i<10;i++){
		printf("Informe as tr�s notas do %d� aluno\n",(i+1));
		printf("N1: ");
		scanf("%f",&notaUm);
		printf("\nN2: ");
		scanf("%f",&notaDois);
		printf("\nN2: ");
		scanf("%f",&notaTres);
		
		media = (notaUm+notaDois+notaTres)/3;
		
		if(media >= 9){
			printf("A m�dia �: %f -- Conceito: A\n",media);
		}else if(media>=7 && media < 9){
			printf("A m�dia �: %f -- Conceito: B\n",media);
		}else if(media >=6 && media < 7){
			printf("A m�dia �: %f -- Conceito: C\n",media);
		}else if(media >=4 && media < 6){
			printf("A m�dia �: %f -- Conceito: D\n",media);
		}else{
			printf("A m�dia �: %f -- Conceito: E\n",media);
		}
	}
	
	
	return 0;
}
