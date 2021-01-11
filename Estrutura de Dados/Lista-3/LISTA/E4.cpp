#include <stdio.h>
#include <stdlib.h>

typedef struct ListaS{ 
	int info; 
	struct ListaS *prox; 
}Lista; 


void inserirNoFinal(int valor, Lista **inicio);
Lista* toLista(int vetor[]);

int main(){
	
}


Lista* toLista(int vetor[], int tam){
	Lista* inicio = NULL;
	if (tam == 0){
		return NULL;
	}else{
		for(int i = 0; i < tam; i++){
			inserirNoFinal(vetor[i], &inicio);
		}
		return inicio;
	}
	
}

void inserirNoFinal(int valor, Lista **inicio){
	Lista *novaCelula;
	if ((*inicio) != NULL){
		Lista *aux = (*inicio);
		while ( aux->prox != NULL){
			aux = aux->prox;
		}
		novaCelula = new Lista();
		novaCelula->info = valor;
		novaCelula->prox = aux->prox;
		aux->prox = novaCelula;
		
	}else{
		novaCelula = new Lista();
		novaCelula->info = valor;
		novaCelula->prox = (*inicio);
		(*inicio) = novaCelula;
	}
}
