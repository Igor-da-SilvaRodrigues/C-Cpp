#include <stdio.h>
#include <string.h>

int main(){
	char string [50];
	int contador;
	
	printf("Insira uma string\n");
	gets(string);
	
	for (contador=0;string[contador]!='\0' && contador<50;contador++)
	    if (string[contador]>96 && string[contador]<123){
	    	string[contador]=string[contador]-32;
		}
	printf("%s",string);
}
