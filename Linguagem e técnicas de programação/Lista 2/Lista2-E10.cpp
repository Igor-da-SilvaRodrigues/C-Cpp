#include <stdio.h>
#include <string.h>

int main(){
	char string2[50], string[50];
	int contador=0, tam;
	
	printf("insira uma string\n");
	gets(string);
	tam = strlen(string)-1;
	
	for (contador=0;contador<=tam;contador++){
		string2[tam-contador]=string[contador];
	}
	string2[contador] = '\0';
	printf("%s\n",string2);
}
