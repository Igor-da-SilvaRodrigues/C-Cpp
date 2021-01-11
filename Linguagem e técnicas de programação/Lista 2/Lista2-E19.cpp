#include <stdio.h>
#include <string.h>
int main(){
    char nomes[5][50];
    int idade[5], contador, maioridade,menoridade,cmaior,cmenor;
     
    for (contador=0;contador<5;contador++){
    printf("Insira seu nome \n");
    scanf("%s",&nomes[contador]);
    printf("Insira sua idade\n");
    scanf("%d",&idade[contador]);
    if (idade[contador]<0){
        printf("!!!IDADE NEGATIVA!!!\ninsira os dados novamente\n");
        contador--;
     }
     if(contador==0){
     	cmaior=0;
     	cmenor=0;
     	maioridade=idade[cmaior];
     	menoridade=idade[cmenor];
	 }
	 else if (idade[contador]<menoridade){
	 	cmenor=contador;
	 	menoridade=idade[cmenor];
	 }
	 else if (idade[contador]>maioridade){
	 	cmaior=contador;
	 	maioridade=idade[cmaior];
	 }
	}
	

     
    printf("a maior idade e de %s, com %d anos\n",nomes[cmaior],maioridade);
    printf("a menor idade e de %s, com %d anos",nomes[cmenor],menoridade);
     
     
     
}
