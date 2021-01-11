#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
	char string [50];
	int contador;
	
	printf("Insira uma string\n");
	gets(string);
	
	for (contador=0;string[contador]!='\0' && contador<50;contador++)
	    if (string[contador]>64 && string[contador]<91){
	    	string[contador]=string[contador]+32;
		}
	printf("%s",string);
	printf("\n");
	system("pause");
}
