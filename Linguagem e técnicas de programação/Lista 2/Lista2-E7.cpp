#include <stdio.h>
#include <string.h>
int main(){
	char string1[100]="\0", string2[100]="\0";
	int contador,validador=1;
	printf("Insira as duas strings\n");
	gets(string1);
	gets(string2);
	
	
	for (contador=0;contador<100 && validador==1;contador++){
		if (string1[contador]==string2[contador]){
			validador=validador;
		}
		else{
			validador=0;
		}
	}
	if (validador==1){
		printf("Strings iguais\n");
	}
	else{
		printf("Strings diferentes\n");
	}
	
	
}
