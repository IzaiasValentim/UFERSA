#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	float notas[5][3];
	int l,c;
	float soma,media;
	
	for(l=0;l<5;l++){
		
		printf("\n Informe a nota do %dº aluno:\n",(l+1));
		
		for(c=0;c<3;c++){
			
			printf("%dº aluno - N %d: ",(l+1),(c+1));
			scanf("%f",&notas[l][c]);
		}
	}
	
	printf("\nMédias:");
	
	for(l=0;l<5;l++){
		
		soma = 0, media =0;
		
		for(c=0;c<3;c++){
			
			soma += notas[l][c];
		
		}
		
		media = soma/3;
		
		printf("\n Média do %dº aluno: %f\n",(l+1),media);
		
		
	}
	
	return 0;
}
