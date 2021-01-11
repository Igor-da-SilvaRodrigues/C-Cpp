#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char nome[50];
	int contador,letras=0;
	printf("Insira um nome\n");
	scanf("%s",&nome);
	
	for (contador=0;contador<50 && nome[contador]!=0;contador++){
		if((nome[contador]>64) && (nome[contador]<91)){
			letras++;			
		}
		if((nome[contador]>96) && (nome[contador]<133)){
			letras++;
		}
	}
	
	printf("%s possui %d letras",nome,letras);
}
