#include <stdio.h>
#include <stdlib.h>
 int main(){
 	
 	FILE *pointer;
 	char caracter;
 	
 	pointer=fopen("arq.txt","a");
 	if(pointer==NULL){
 		return(1);
	 }
 	
 	while (caracter != '0'){
 		printf("Insira um caracter a ser escrito...   ");
 		scanf("%c%*C",&caracter);
 		if(caracter != '0'){
 		fprintf(pointer,"%c",caracter);
 	    }
	 }
	 
	 fclose(pointer);
	 pointer=fopen("arq.txt","r");
	 if (pointer==NULL){
	 	return (1);
	 }
	 do{
	 	caracter=fgetc(pointer);
	 	printf("%c",caracter);
	 }while(caracter!=EOF);
	 
 	
 }
