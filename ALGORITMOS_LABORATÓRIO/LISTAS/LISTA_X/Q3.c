#include<stdio.h>
#include<locale.h>

void exibirM(int mat[2][3]);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int matA[2][3],matB[2][3],matS[2][3];
	int l,c;
	
	printf("Informe seis valores inteiros para a matriz A:");
	
	for(l=0; l<2; l++){
		
		for(c=0; c<3;c++){
			printf("\nvalor: ");
			scanf("%d",&matA[l][c]);
		}
		
	}
	system("cls");
	printf("Informe seis valores inteiros para a matriz B:");
	
	for(l=0; l<2; l++){
		
		for(c=0; c<3;c++){
			printf("\nvalor: ");
			scanf("%d",&matB[l][c]);
			
			matS[l][c] = (matA[l][c]+matB[l][c]);
		}
		
	}
	system("cls");

	printf("Soma:\n");
	exibirM(matA);printf("\n +");exibirM(matB);printf("\n =");exibirM(matS);
	
	
	
	
	
	
	return 0;
}

void exibirM(int mat[2][3]){
	int l,c;
	printf("\n");
	for(l=0; l<2; l++){
		
		for(c=0; c<3;c++){
					
			printf("%d",mat[l][c]);	
			
		}
		
		printf("\n");
	}





}
