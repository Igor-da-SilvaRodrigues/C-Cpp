#include <stdio.h>


int main(){
	int ano;
	int validador;
	printf("Insira um ano, para verificar se este e bissexto ou nao:\n");
	scanf("%d%*C",&ano);
	if((ano%100)==0){
		if((ano%400)==0){
			validador=1;
		}
		else{
			validador=0;
		}
	}
	
	if ((ano%4)==0){
		validador=1;
	}
	
	if (validador==1){
	printf("O ano %d",ano);
	printf(" e bissexto");
	}
	else{
		printf("O ano %d", ano);
		printf(" NAO e bissexto");
	}
	   
}

