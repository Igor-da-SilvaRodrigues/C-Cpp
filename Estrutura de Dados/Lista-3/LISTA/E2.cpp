#include <stdio.h>
#include <stdlib.h>

typedef struct ListaS{ 
	int info; 
	struct ListaS *prox; 
}Celula;

void inserirNoFinal(int valor, Celula **inicio);
Celula* copiar(Celula* alvo);

int main(){
} 


Celula* copiar(Celula* alvo){
	Celula* Inicio = NULL;
	
	while (alvo != NULL){
		inserirNoFinal(alvo->info, &Inicio);
		alvo = alvo->prox;
	}
	
	return Inicio;
}


void inserirNoFinal(int valor, Celula **inicio){
	Celula *novaCelula;
	if ((*inicio) != NULL){
		Celula *aux = (*inicio);
		while ( aux->prox != NULL){
			aux = aux->prox;
		}
		novaCelula = new Celula();
		novaCelula->info = valor;
		novaCelula->prox = aux->prox;
		aux->prox = novaCelula;
		
	}else{
		novaCelula = new Celula();
		novaCelula->info = valor;
		novaCelula->prox = (*inicio);
		(*inicio) = novaCelula;
	}
}

