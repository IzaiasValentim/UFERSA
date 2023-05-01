#include<stdio.h>
#include<locale.h>

void exibirM(int mat[4][2]);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int matA[4][2],matB[4][2];
	int l,c;
	
	printf("Informe seis valores inteiros para a matriz A:");
	
	for(l=0; l<=3; l++){
		
		for(c=0; c<=1;c++){
			printf("\nvalor: ");
			scanf("%d",&matA[l][c]);
			matB[3-l][1-c] = matA[l][c]; 
		}
		
	}

	system("cls");
	
	printf("Matriz A:");
	exibirM(matA);
	
	printf("Matriz B:");
	exibirM(matB);
	
	return 0;
}

void exibirM(int mat[4][2]){
	int l,c;
	printf("\n");
	for(l=0; l<=3; l++){
		
		for(c=0; c<=1;c++){
					
			printf("%d ",mat[l][c]);	
			
		}
		
		printf("\n");
	}





}
