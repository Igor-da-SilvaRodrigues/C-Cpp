#include <stdio.h>
#include <stdlib.h>

int main(){
	char string[50]="\0";
	int contador=0;
	
	printf("Insira uma string\n");
	gets(string);
	
	for (contador=0;contador<50;contador++){
		if (string[contador]=='0'){
			string[contador]='1';
		}
	}
	printf("%s",string);
	printf("\n");
	system("\npause");
}
