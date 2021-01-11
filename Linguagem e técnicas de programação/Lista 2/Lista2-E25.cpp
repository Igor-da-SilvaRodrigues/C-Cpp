#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char string[50], retorno[50];
	int contador,tam;
	
	printf("Insira uma frase a ser criptografada\n");
	scanf("%s%*C",string);
	tam=strlen(string)-1;
	
	for (contador=0;contador<=tam;contador++){
		
		if ((90-string[contador])>=3 && string[contador]>64 && string[contador]<91 || (122-string[contador])>=3 && string[contador]>96 && string[contador]<123 ){
			
		retorno[contador]=string[contador]+3;
		
	    }
	    else if (string[contador>64 && string [contador]<91]){
	    	retorno[contador]=67-(90-string[contador]);
		}
		else if (string[contador]>96 && string[contador]<123){
			retorno[contador]=99-(122-string[contador]);
		}
		
	}
	
	printf("%s",retorno);
}
