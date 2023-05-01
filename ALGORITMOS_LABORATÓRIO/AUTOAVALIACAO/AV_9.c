#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int n,m,l,c;
	
	printf("Informe as dimensões(n x m) da matriz \n");
	printf("n: ");
	scanf("%d",&n);
	
	printf("m: ");
	scanf("%d",&m);
	
	int matA[n][m],matB[n][m];
	
	system("cls");
	
	printf("Informe os %d valores da matriz: A%dx%d \n",(n*m),n,m);
	
	for(l=0; l<n; l++){
		
		for(c=0; c<m;c++){
			printf("\nvalor: ");
			scanf("%d",&matA[l][c]);
			matB[l][c] = -1*matA[l][c];
		}
		
	}
	
	system("cls");

	printf("Matriz A: \n");
	
	for(l=0; l<n; l++){
		
		for(c=0; c<m;c++){
					
			printf("%d ",matA[l][c]);	
			
		}
		printf("\n");
	}
	
	printf("Matriz B: \n");
	
	for(l=0; l<n; l++){
		
		for(c=0; c<m;c++){
					
			printf("%d ",matB[l][c]);	
			
		}
		printf("\n");
	}
	return 0;
}


