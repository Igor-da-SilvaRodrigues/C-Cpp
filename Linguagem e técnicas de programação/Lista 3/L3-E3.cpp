#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char stringlida[100];
	int cont,soma=0;
	FILE *pointer;
	
	pointer=fopen("L3E3.txt","r");
	
	//if( fgets (str, 60, fp)!=NULL ) {
		
	while (fgets(stringlida,100,pointer)!=NULL){
		soma=soma+atoi(stringlida);
		printf("%d\n",atoi(stringlida));
		//puts(stringlida);
	}
	
	printf("total:%d",soma);
}
