#include <stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int idade;
	int rept =1;
	
	while(rept <= 10){
		printf("Informe a idade do %d� usu�rio ",rept);
		scanf("%d",&idade);
		
		if(idade>=18){
			printf("O %d� usu�rio � maior de idade\n\n\n",rept);
		
		}else{
			printf("O %d� usu�rio � menor de idade\n\n\n",rept);
			
		}
		rept = rept+1;
	}
	
	return 0;
}
