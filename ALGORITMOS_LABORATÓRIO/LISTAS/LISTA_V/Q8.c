#include<stdio.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int idadeAnos=0,dias=0;
	
	printf("Informe sua idade:...\n");
	scanf("%d",&idadeAnos);
	
	dias = idadeAnos*365;
	
	printf("Você já viveu aproximadamente: %d",dias);
	
	
	return 0;
}
