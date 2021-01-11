#include <stdio.h>

int main(){
	char string[50]="\0";
	int contador=0,incremento=0;
	
	printf("insira uma string\n");
	gets(string);
	
	for (contador=0;contador<50;contador++){
		if (string[contador]=='1'){
			incremento++;
		}
	}
	printf("A string possui %d uns",incremento);
	
}
