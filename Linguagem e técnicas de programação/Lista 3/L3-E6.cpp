#include <stdio.h>
#include <stdlib.h>

typedef struct ficha {
		char matricula[100];
		char sobrenome[15];
		int ano;
	}cadastro;


int main(){
	// pra cada aluno: matricula,sobrenome,anonascimento
    cadastro ficha;
	int v;
	char string[100];
	FILE *pointer;


	printf("Deseja carregar os dados do arquivo na memoria?\n1-sim\n");
	scanf("%d",&v);
	if (v==1){
	pointer=fopen("cadastro.txt","r");
	while(fgets(string,100,pointer) != NULL){
		printf("%s",string);
		}
	}
	
	printf("\n\nPreencha a ficha cadastral\nmatricula\nsobrenome\nano\n");
	scanf("%s",&ficha.matricula);
	scanf("%s",&ficha.sobrenome);
	scanf("%d",&ficha.ano);
	
	pointer=fopen("cadastro.txt","a");
	fprintf(pointer,"%s\n%s\n%d\n-------\n",ficha.matricula,ficha.sobrenome,ficha.ano);
	
	fclose(pointer);
	printf("Voce armazenou os seguintes dados:\n");
	printf("%s\n%s\n%d\n-------\n",ficha.matricula,ficha.sobrenome,ficha.ano);
	
	
	
}
