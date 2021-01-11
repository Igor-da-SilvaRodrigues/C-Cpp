#include <stdio.h>
#include <stdlib.h>

typedef struct ListaD{ 
	int info; 
	struct ListaD *prox, *ant; 
}ListaD; 

void inserirInicio(ListaD** Inicio, ListaD** Fim, int val);
void inserirFim(ListaD** Inicio, ListaD** Fim, int val);
ListaD* buscar(ListaD *Inicio, ListaD *Fim, int val);
void removerLista(ListaD **Inicio, ListaD **Fim);
void removerPrimeiraOcorrencia(ListaD **Inicio, ListaD **Fim, int val);
int contCel(ListaD* Inicio, ListaD* Fim);
void intercalarListasOrdenadasCrescente(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B);
void copiarLista(ListaD* Inicio_A, ListaD* Fim_A, ListaD** Inicio_B, ListaD** Fim_B);

int main(){
	return 0;
}

void copiarLista(ListaD* Inicio_A, ListaD* Fim_A, ListaD** Inicio_B, ListaD** Fim_B){
	ListaD* aux;
	if (Inicio_A != NULL){
		(*Inicio_B) = NULL;
		(*Fim_B) = NULL;
		aux = Inicio_A;
		while(aux != Fim_A){
			inserirFim(Inicio_B, Fim_B, aux->info);			
			aux = aux->prox;
		}
		inserirFim(Inicio_B, Fim_B, aux->info);
	}	
}

void intercalarListasOrdenadasCrescente(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B){
	ListaD* Inicio_C = NULL;
	ListaD* Fim_C = NULL;
	
	ListaD* aux_A;
	ListaD* aux_B;
	
	if ((*Inicio_A) == NULL){
		
		(*Inicio_A) = (*Inicio_B);
		(*Fim_A) = (*Fim_B);
	}else if ((*Inicio_B) != NULL){
		aux_A = (*Inicio_A);
		aux_B = (*Inicio_B);
		
		while (aux_A != (*Fim_A) || aux_B != (*Fim_B)){
			
			if (aux_A != (*Fim_A) && aux_B != (*Fim_B)){
				if (aux_A->info <= aux_B->info){
					inserirFim(&Inicio_C, &Fim_C, aux_A->info);
					aux_A = aux_A->prox;
				}else{
					inserirFim(&Inicio_C, &Fim_C, aux_B->info);
					aux_B = aux_B->prox;
				}
			}else{
				
				if(aux_A != (*Fim_A)){
					inserirFim(&Inicio_C, &Fim_C, aux_A->info);
					aux_A = aux_A->prox;
				}
				
				if (aux_B != (*Fim_B)){
					inserirFim(&Inicio_C, &Fim_C, aux_A->info);
					aux_A = aux_A->prox;
				}
			}
		}
		if (aux_A->info <= aux_B->info){
			inserirFim(&Inicio_C, &Fim_C, aux_A->info);
			inserirFim(&Inicio_C, &Fim_C, aux_B->info);
		}else{
			inserirFim(&Inicio_C, &Fim_C, aux_B->info);
			inserirFim(&Inicio_C, &Fim_C, aux_A->info);
		}
		
		
		(*Inicio_A) = Inicio_C;
		(*Fim_A) = Fim_C;
	}
}

int contCel(ListaD* Inicio, ListaD* Fim){
	int cont = 0;
	while (Inicio != Fim){
		cont++;
		Inicio = Inicio->prox;
	}
	return cont+1;
}

void removerPrimeiraOcorrencia(ListaD **Inicio, ListaD **Fim, int val){
	ListaD *aux;
	if ((*Inicio)!= NULL){
		while ((*Inicio)->ant != (*Fim)){ //posiciona o inicio ao inicio da lista;
			(*Inicio) = (*Inicio)->ant;
		}
		aux = (*Inicio);
		if (aux->prox == aux){ 
	 	// Se a lista so possui uma ocorrencia;
			if (aux->info == val) {
				removerLista(Inicio, Fim);
				aux = NULL;	
			}
		}else{

			aux = buscar((*Inicio), (*Fim), val);// navega ate o valor desejado se ele existe, se nao navega ate o final da lista, aux = NULL.
			if (aux != NULL){ //Checa se o valor foi encontrado;
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
				if (aux == (*Fim)){
					(*Fim) = aux->ant;
				}else if (aux == (*Inicio)){
					(*Inicio) = aux->prox;
				}
				delete(aux);
				aux = NULL;
			}				
		}
	}else{
		printf("%s\n", "LISTA NAO INICIALIZADA!\n");
	}
}

void removerLista(ListaD **Inicio, ListaD **Fim){
	ListaD *aux;
	if ((*Inicio) != NULL){
		//aux = (*Inicio);
		while ((*Inicio)->ant != (*Fim)){
			(*Inicio) = (*Inicio)->ant;
		}
		aux = (*Inicio)->prox;
		while (aux != (*Fim)){
			delete((*Inicio));
			(*Inicio) = aux;
			aux = aux->prox;
		}
		delete((*Inicio));
		(*Inicio) = NULL;
		(*Fim) = NULL;
	}
}

ListaD* buscar(ListaD *Inicio, ListaD *Fim, int val){

	if (Inicio != NULL && Fim != NULL){
		//while (Inicio != NULL && Fim != NULL){
		do{
			if (Inicio->info == val){
				return Inicio;
			}else if (Fim->info == val){				
					return Fim;
				}
			if (Inicio == Fim){
				break;
			}
			Inicio = Inicio->prox;
			Fim = Fim->ant;
		}while (!(Inicio->ant == Fim || Fim->prox == Inicio));
	}
	return NULL;
}



void inserirInicio(ListaD** Inicio, ListaD** Fim, int val){
	
	ListaD* novaCelula;
	//novaCelula = malloc(sizeof(Celula));
	novaCelula = new ListaD();
	novaCelula->info = val;
	if ((*Inicio) == NULL){
		(*Inicio) = novaCelula;
		(*Fim) = novaCelula;
		novaCelula->ant = (*Fim);
		novaCelula->prox = (*Inicio);
	}else{
		(*Inicio)->ant = novaCelula;
		novaCelula->prox = (*Inicio);
		novaCelula->ant = (*Fim);
		(*Fim)->prox = novaCelula;
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
		(*Inicio)->ant = novaCelula;
		novaCelula->prox = (*Inicio);
		novaCelula->ant = (*Fim);
		(*Fim)->prox = novaCelula;
		(*Fim) = novaCelula;
	}
}
