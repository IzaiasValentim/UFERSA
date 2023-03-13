#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	printf("Hello, world!");
	
	printf("\n\nHello,\nWorld!\n\n");
	
	printf("\tHello, World!\n");
	
	printf("Hello,\n\tWorld!");
	
	return 0;
}
