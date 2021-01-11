#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
	char S[50], C;
	int I, contador,v,posicao;
	
	
	printf("Insira uma string\n");
	gets(S);
	printf("Insira um caracter a ser buscado\n");
	scanf("%c",&C);
	for(v=1;v!=0;){
	   printf("Insira a posicao pela qual a busca deve comecar\n");
	   scanf("%d",&I);
	   if(I>strlen(S)){
	   	 v=1;
	   }
	   else{
	   	v=0;
	   }
    }
	posicao=0;
	for (contador=I;S[contador]!=C;contador++,posicao++){	}
	
	printf("\nCaracter encontrado na posicao:   %d",posicao);
}
