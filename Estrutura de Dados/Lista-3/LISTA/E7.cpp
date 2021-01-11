#include <stdio.h>
#include <stdlib.h>
typedef struct ListaS{ 
	int info; 
	struct ListaS *prox; 
}Lista;

void inserirNoInicio(int valor, Lista** inicio);
int contCel(Lista* Inicio);
void inverterLista(Lista** inicio);

int main(){
	
} 


void inverterLista(Lista** inicio){
	Lista* aux_a;
	Lista* aux_b;
	Lista* aux_c = NULL;

	if ((*inicio) != NULL){
		aux_b = (*inicio);
		aux_a = aux_b->prox;
		while (aux_a != NULL){
			aux_b->prox = aux_c;
			aux_c = aux_b;
			aux_b = aux_a;
			aux_a = aux_a->prox;
		}
		aux_b->prox = aux_c;
		(*inicio) = aux_b;
	}
}

void inserirNoInicio(int valor, Lista** inicio){
	Lista* novaCelula;
	//novaCelula = new celulaLista();
	novaCelula = new Lista();
		novaCelula->info = valor;
		novaCelula->prox = (*inicio);
		(*inicio) = novaCelula;
}

int contCel(Lista* Inicio){
	int cont = 0;
	Lista* aux;
	if (Inicio != NULL){
		aux = Inicio;
		while (aux != NULL){
			cont++;
			aux = aux->prox;
		}
	}
	return cont;
}
