//Fila-FIFO
//Igor da Silva Rodrigues
//22/11/20
#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
	struct celula* prev;
	struct celula* prox;
	int dado;
}Celula;

typedef struct fila{
	Celula* inicio;
	Celula* fim;
				
}Fila;
void inserirNaFila(Fila** fila, int val);
int removerDaFila(Fila* fila);


void inserirInicio(Celula** Inicio, Celula** Fim, int val);
void inserirFim(Celula** Inicio, Celula** Fim, int val);
void imprimirInicio(Celula *Inicio);
void imprimirFim(Celula *Fim);
Celula* buscar(Celula *Inicio, Celula *Fim, int val);
void alterarValor(Celula *Inicio, Celula *Fim, int val, int substituto);
void removerLista(Celula **Inicio, Celula **Fim);
void removerPrimeiraOcorrencia(Celula **Inicio, Celula **Fim, int val);
void removerUltimaOcorrencia(Celula **Inicio, Celula **Fim, int val);
void pause();


Fila* fila = NULL;
int main(){
	int v, op;
	while(1){
		printf("1-Inserir na Fila>>\n2-remover da Fila>>\n0-Sair>>\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("    Entre com o numero a ser introduzido a fila:\n    ");
				scanf("%d", &v);
				inserirNaFila(&fila, v);
				break;
			case 2:
				v = removerDaFila(fila);
				printf("    |%d\n", v);
				break;
			case 0:
				return 0;
			case 666:
				system("cls");
				break;
			default:
				printf("Opcao invalida!!\n");
				//pause();
		}
	}
	
}

void inserirNaFila(Fila** fila, int val){
	if ((*fila) != NULL) {
		//printf("entrou\n");
		inserirInicio(&((*fila)->inicio), &((*fila)->fim),  val);
	}else{
		//printf("Entrou\n");
		(*fila) = new Fila();
		(*fila)->inicio = NULL;
		(*fila)->fim = NULL;
		inserirNaFila(fila, val);
	}
}

int removerDaFila(Fila* fila){
	int val;
	if (fila != NULL && (fila->inicio)!= NULL && (fila->fim)!= NULL){
		val = (fila->fim->dado);
		removerUltimaOcorrencia(&(fila->inicio), &(fila->fim), val);
		return val;		
	}else{
		printf("Fila vazia ou nula!!\n");
	}
}




void inserirInicio(Celula** Inicio, Celula** Fim, int val){
	
	Celula* novaCelula;
	//novaCelula = malloc(sizeof(Celula));
	novaCelula = new Celula();
	novaCelula->dado = val;
	if ((*Inicio) == NULL){
		novaCelula->prev = (*Inicio);
		novaCelula->prox = (*Fim);
		(*Inicio) = novaCelula;
		(*Fim) = novaCelula;
	}else{
		novaCelula->prev = (*Inicio)->prev;
		novaCelula->prox = (*Inicio); 
		(*Inicio)->prev = novaCelula;
		(*Inicio) = novaCelula;
	}
	
}

void inserirFim(Celula** Inicio, Celula** Fim, int val){
	Celula *novaCelula;
	if ((*Fim) == NULL){
		inserirInicio(Inicio, Fim, val);
		
	}else{
		novaCelula = new Celula();
		novaCelula->dado = val;
		novaCelula->prev = (*Fim);
		novaCelula->prox = (*Fim)->prox;
		(*Fim)->prox = novaCelula;
		(*Fim) = novaCelula;
	}
}

void imprimirInicio(Celula *Inicio){
	while (Inicio != NULL){
		printf("%d\n", Inicio->dado);
		Inicio = Inicio->prox;
	}
}

void imprimirFim(Celula *Fim){
	while (Fim != NULL){
		printf("%d\n", Fim->dado);
		Fim = Fim->prev;
	}
}

Celula* buscar(Celula *Inicio, Celula *Fim, int val){

	if (Inicio != NULL && Fim != NULL){
		//while (Inicio != NULL && Fim != NULL){
		while (Inicio != NULL && Fim != NULL && !(Inicio->prev == Fim || Fim->prox == Inicio)){
			if (Inicio->dado == val){
				return Inicio;
			}else if (Fim->dado == val){				
					return Fim;
				}
			if (Inicio == Fim){
				break;
			}
			Inicio = Inicio->prox;
			Fim = Fim->prev;
		}

		/*if (Inicio != NULL && Fim != NULL){
			printf("%s\n", "EURECAAAA");
		}else{
			printf("%s\n", "HArd break");
		}*/

	}
	return NULL;
}

void alterarValor(Celula *Inicio, Celula *Fim, int val, int substituto){
	Celula *aux = buscar(Inicio, Fim, val);
	if (aux == NULL){
		printf("VALOR NAO ENCONTRADO!\n");
		pause();
	}else{
		aux->dado = substituto;
	}
}

void removerLista(Celula **Inicio, Celula **Fim){
	Celula *aux;
	if ((*Inicio) != NULL){
		//aux = (*Inicio);
		while ((*Inicio)->prev != NULL){
			(*Inicio) = (*Inicio)->prev;
		}
		aux = (*Inicio)->prox;
		while (aux != NULL){
			delete((*Inicio));
			(*Inicio) = aux;
			aux = aux->prox;
		}
		delete((*Inicio));
		(*Inicio) = NULL;
		(*Fim) = NULL;
	}
}

void removerPrimeiraOcorrencia(Celula **Inicio, Celula **Fim, int val){
	Celula *aux;
	if ((*Inicio)!= NULL){
		while ((*Inicio)->prev != NULL){ //posiciona o inicio ao inicio da lista;
			(*Inicio) = (*Inicio)->prev;
		}
		aux = (*Inicio);
		if (aux->prox == NULL){ 
	 	// Se a lista so possui uma ocorrencia;
			if (aux->dado == val) {
				removerLista(Inicio, Fim);
				aux = NULL;	
			}
		}else{
			//while (aux != NULL && aux->dado != val){
			//	aux = aux->prox; 
			//}
			aux = buscar((*Inicio), (*Fim), val);// navega ate o valor desejado se ele existe, se nao navega ate o final da lista, aux = NULL.
			if (aux != NULL){ //Checa se o valor foi encontrado;
				if (aux->prev == NULL){ //Se for a primeira casa;
					(*Inicio) = aux->prox;
					aux->prox = NULL;
					delete(aux);
					(*Inicio)->prev = NULL;
					aux = NULL;
				}else if (aux->prox == NULL){ //Se for a ultima casa;
					(*Fim) = aux->prev;
					aux->prev = NULL;
					delete(aux);
					((*Fim)->prox) = NULL;
					aux = NULL;
				}else{ //Se estiver no meio;
					aux->prev->prox = aux->prox;
					aux->prox->prev = aux->prev;
					delete(aux);
					aux = NULL;
				}				
			}
		}
	}else{
		printf("%s\n", "LISTA NAO INICIALIZADA!\n");
		pause();
	}
}

void removerUltimaOcorrencia(Celula **Inicio, Celula **Fim, int val){
	Celula* aux;
	if ((*Inicio) != NULL && (*Fim) != NULL){
		aux = (*Fim);
		if (aux->prox == NULL){ //somente se o Fim for realmente a ultima casa...
			if (aux->prev == NULL){ //se a Lista só possui uma casa;
				if (aux->dado == val){
					removerLista(Inicio, Fim);
					aux = NULL;
				}				
			}else{
				while(aux != NULL && aux->dado != val){
					aux = aux->prev;
				}
				
				if (aux != NULL){
					if (aux->prev == NULL){//se for a primeira casa
						(*Inicio) = aux->prox;
						aux->prox = NULL;
						delete(aux);
						(*Inicio)->prev = NULL;
						aux = NULL;
					}else if (aux->prox == NULL){//se for a ultima casa;
						(*Fim) = aux->prev;
						aux->prev = NULL;
						delete(aux);
						(*Fim)->prox = NULL;
						aux = NULL;
					}else{
						aux->prox->prev = aux->prev;
						aux->prev->prox = aux->prox;
						delete(aux);
						aux = NULL;	
					}					
				}				
			}					
		}				
	}else{
		printf("%s\n", "LISTA NAO INICIALIZADA!\n");
		pause();
	}	
}

void pause(){
	fflush(stdin);
	printf("Preciona qualquer tecla para continuar. . .\n");
	getchar();
}
