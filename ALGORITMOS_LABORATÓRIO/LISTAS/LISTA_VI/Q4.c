#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portguese");
	int quantidade;
	float precoUnit,precoTotal;
	
	printf("Quantas ma�as desejas comprar?\n");
	scanf("%d",&quantidade);
	
	if(quantidade> 0 && quantidade < 12){
		
		precoUnit = 1.30;
		precoTotal = quantidade*precoUnit;
	
	}else if(quantidade> 0 && quantidade >= 12){
	
		precoUnit = 1.10;
		precoTotal = quantidade*precoUnit;
		
	}else{
		
		printf("At� mais!");
		return 1;
	}
	
	printf("%d ma�as fica por: %.2f - UND: %f",quantidade, precoTotal,precoUnit);
	
	return 0;
}
