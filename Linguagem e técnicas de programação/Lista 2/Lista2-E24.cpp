#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
	char a[50],b[50];
	int contador;
	
	printf ("Insira duas palavras:\n");
	scanf("%s",&a);
	scanf("%s",&b);
	
	for (contador=0;contador<50;contador++){
		if (a[contador]<b[contador]){
			printf("primeira palavra-----segunda palavra");
			break;
		}
		else if (a[contador]>b[contador]){
			printf("segunda palavra-----primeira palavra");
			break;
		}
		else{
		}
	}
	
	
}
