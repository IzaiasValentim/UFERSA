#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	float notas[5][3];
	int l,c;
	float soma,media;
	
	for(l=0;l<5;l++){
		
		printf("\n Informe a nota do %d� aluno:\n",(l+1));
		
		for(c=0;c<3;c++){
			
			printf("%d� aluno - N %d: ",(l+1),(c+1));
			scanf("%f",&notas[l][c]);
		}
	}
	
	printf("\nM�dias:");
	
	for(l=0;l<5;l++){
		
		soma = 0, media =0;
		
		for(c=0;c<3;c++){
			
			soma += notas[l][c];
		
		}
		
		media = soma/3;
		
		printf("\n M�dia do %d� aluno: %f\n",(l+1),media);
		
		
	}
	
	return 0;
}
