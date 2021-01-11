#include <stdio.h>
#include <string.h>
int main(){
	char string[50],l1,l2;
	int contador, tam;
	
	printf("Insira uma string\n");
	gets(string);
	printf("Insira o caracter a ser substituido\n");
	scanf("%c%*C",&l1);
	printf("Insira o caracter que substituira o anterior\n");
	scanf("%c%*C",&l2);
    
	tam = strlen(string);
	
	for (contador=0;contador < tam ;contador++){
		if (string[contador] == l1){
			string[contador] = l2;
	   }
	}
	
	printf("%s",string);
	
}
