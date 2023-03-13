#include<stdio.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	float n1,n2;
	
	printf("Informe dois números a seguir: ...\n");
	scanf("%f%f",&n1,&n2);
	
	printf("Resultado: %f ~ %f",n1*2,n2*3);
	
	
}
