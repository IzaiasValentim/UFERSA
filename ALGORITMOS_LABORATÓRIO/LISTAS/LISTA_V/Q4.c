#include<stdio.h>
#include<locale.h>

int main(){
	float tc,tf;
	
	printf("Informe a temperatura em celcius: \n");
	scanf("%f",&tc);
	
	tf = ((tc*1.8)+32);
	
	printf("%fCº em Fahrenheit: %.1fF",tc,tf);]
	
	return 0;
}
