#include <stdio.h>
#include <stdlib.h>

typedef struct ListaD{ 
	int info; 
	struct ListaD *prox, *ant; 
}ListaD;

void inserirFim(ListaD** Inicio, ListaD** Fim, int val);
void inserirInicio(ListaD** Inicio, ListaD** Fim, int val);
ListaD* concatenar(ListaD** inicioA,ListaD** fimA, ListaD* inicioB,ListaD* fimB);
void quebrarLista(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B, int v);
void intercalarListas(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B);
void intercalarListasOrdenadasCrescente(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B);

int main(){
	
}


void intercalarListasOrdenadasCrescente(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B){//intercalar duas listas crescente em uma lista crescente.
	ListaD* Inicio_C = NULL;
	ListaD* Fim_C = NULL;
	
	ListaD* aux_A;
	ListaD* aux_B;
	if ((*Inicio_A == NULL)){
		(*Inicio_A) = (*Inicio_B);
		(*Fim_A) = (*Fim_B);
	}else if ((*Inicio_B) != NULL){
		aux_A = (*Inicio_A);
		aux_B = (*Inicio_B);
		while (aux_A != NULL || aux_B != NULL){
			
			if (aux_A != NULL && aux_B != NULL){
				
				if (aux_A->info <= aux_B->info){
					inserirFim(&Inicio_C, &Fim_C, aux_A->info);
					aux_A = aux_A->prox;
				}else{
					inserirFim(&Inicio_C, &Fim_C, aux_B->info);
					aux_B = aux_B->prox;
				}

			}else{
				if (aux_A != NULL){
					inserirFim(&Inicio_C, &Fim_C, aux_A->info);
					aux_A = aux_A->prox;
				}
				
				if (aux_B != NULL){
					inserirFim(&Inicio_C, &Fim_C, aux_B->info);
					aux_B = aux_B->prox;
				}
			}
			
		
		}
		(*Inicio_A) = Inicio_C;
		(*Fim_A) = Fim_C;
	}
}


void intercalarListas(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B){
	ListaD* Inicio_C = NULL;
	ListaD* Fim_C = NULL;
	
	ListaD* aux_A;
	ListaD* aux_B;
	if ((*Inicio_A == NULL)){
		(*Inicio_A) = (*Inicio_B);
		(*Fim_A) = (*Fim_B);
	}else if ((*Inicio_B) != NULL){
		aux_A = (*Inicio_A);
		aux_B = (*Inicio_B);
		while (aux_A != NULL || aux_B != NULL){
			
			if (aux_A != NULL){
				inserirFim(&Inicio_C, &Fim_C, aux_A->info);
				aux_A = aux_A->prox;
			}
			if (aux_B != NULL){
				inserirFim(&Inicio_C, &Fim_C, aux_B->info);
				aux_B = aux_B->prox;
			}
		}
		(*Inicio_A) = Inicio_C;
		(*Fim_A) = Fim_C;
	}
}


void quebrarLista(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B, int v){// quebra a lista A e armazena a lista restante em B
	ListaD* aux;
	if ((*Inicio_A) != NULL){
		aux = (*Inicio_A);
		while (aux != NULL && aux->info != v){
			aux = aux->prox;
		}
		if (aux != NULL){
			(*Fim_B) = (*Fim_A);
			(*Fim_A) = aux;
			(*Inicio_B) = aux->prox;
			aux->prox = NULL;
			(*Inicio_B)->ant = NULL;
			
		}
	}
	
}


ListaD* concatenar(ListaD** inicioA,ListaD** fimA, ListaD* inicioB,ListaD* fimB){
	ListaD* aux;
	if (inicioA != NULL){
		aux = inicioB;
		while (aux != NULL){
			inserirFim(inicioA, fimA, aux->info);
			aux = aux->prox;
		}
	}else{
		return inicioB;
	}
	return (*inicioA);
} 


void inserirInicio(ListaD** Inicio, ListaD** Fim, int val){
	
	ListaD* novaCelula;
	//novaCelula = malloc(sizeof(Celula));
	novaCelula = new ListaD();
	novaCelula->info = val;
	if ((*Inicio) == NULL){
		novaCelula->ant = (*Inicio);
		novaCelula->prox = (*Fim);
		(*Inicio) = novaCelula;
		(*Fim) = novaCelula;
	}else{
		novaCelula->ant = (*Inicio)->ant;
		novaCelula->prox = (*Inicio); 
		(*Inicio)->ant = novaCelula;
		(*Inicio) = novaCelula;
	}
	
}

void inserirFim(ListaD** Inicio, ListaD** Fim, int val){
	ListaD *novaCelula;
	if ((*Fim) == NULL){
		inserirInicio(Inicio, Fim, val);
		
	}else{
		novaCelula = new ListaD();
		novaCelula->info = val;
		novaCelula->ant = (*Fim);
		novaCelula->prox = (*Fim)->prox;
		(*Fim)->prox = novaCelula;
		(*Fim) = novaCelula;
	}
}
