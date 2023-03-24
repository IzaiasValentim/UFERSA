#include <stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int idade;
	int rept =1;
	
	while(rept <= 10){
		printf("Informe a idade do %dº usuário ",rept);
		scanf("%d",&idade);
		
		if(idade>=18){
			printf("O %dº usuário é maior de idade\n\n\n",rept);
		
		}else{
			printf("O %dº usuário é menor de idade\n\n\n",rept);
			
		}
		rept = rept+1;
	}
	
	return 0;
}
