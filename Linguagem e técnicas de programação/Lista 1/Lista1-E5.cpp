#include <stdio.h>
int main(){
	int numero, subtracao;
	printf("Insira um numero\n");
	scanf("%d",&numero);
	subtracao=0;
	while (subtracao<=20){
		printf(":%d\n",(numero-subtracao));
		
		
		subtracao++;
	}
}
