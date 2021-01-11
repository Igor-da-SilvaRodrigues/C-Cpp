#include <stdio.h>
#include <string.h>

int main(){
	char string[50],varaux;
	int contador,tam,contador2;
	
	printf("Insira uma string\n");
	gets(string);
	tam=strlen(string)-1;
	for (contador=0;contador<=tam;contador++){
		if (string[contador]=='a' || string[contador]=='e' || string[contador]=='i' || string[contador]=='o' || string[contador]=='u' || string[contador]=='A' || string[contador]=='E' || string[contador]=='I' || string[contador]=='O' || string[contador]=='U'){
			for (contador2=contador;contador2<=tam;contador2++){
				varaux=string[contador2+1];
				string[contador2]=varaux;
			}
		contador--;	
		} 
	} 
	printf("%s",string);
}
