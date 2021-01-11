#include <stdlib.h>
#include <stdio.h>

int main(){
	char nome[50];
	int contador,limite=4;
	printf("Insira um nome\n");
	gets(nome);
	
	
	for (contador=0;contador<limite;contador++){
		if(nome[contador]==' '  || nome[contador]=='-'){
			limite++;			
		}
		else{
			printf("%c",nome[contador]);
		}
		
	}
}
