//;Igor da Silva Rodrigues
//14/11/20
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


typedef struct celula{
	struct celula* prev;
	struct celula* prox;
	int dado;
}Celula;

Celula* inicio = NULL;
Celula* fim = NULL;


void inserirInicio(Celula** Inicio, Celula** Fim, int val);
void inserirFim(Celula** Inicio, Celula** Fim, int val);
void imprimirInicio(Celula *Inicio);
void imprimirFim(Celula *Fim);
Celula* buscar(Celula *Inicio, Celula *Fim, int val);
void alterarValor(Celula *Inicio, Celula *Fim, int val, int substituto);
void removerLista(Celula **Inicio, Celula **Fim);
void removerPrimeiraOcorrencia(Celula **Inicio, Celula **Fim, int val);
void pause();

int main(){
	Celula *p;
	char a;
	int opcao, v, g;
	while(1){
		//system("cls");
		printf("1- Imprimir do Inicio\n2- Imprimir do final\n3- Inserir no Inicio\n4- Inserir no Fim\n5- Alterar um valor\n6- Apagar a lista\n7- Apagar um valor\n0- Sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//system("cls");
				imprimirInicio(inicio);
				pause();
				break;
			case 2:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//system("cls");
				imprimirFim(fim);
				pause();
				break;
			case 3:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//system("cls");
				printf("Insira o numero a ser inserido: ");
				scanf("%d", &v);
				inserirInicio(&inicio, &fim, v);
				break;
			case 4:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//system("cls");
				printf("Insira o numero a ser inserido: ");
				scanf("%d", &v);
				inserirFim(&inicio, &fim, v);
				break;
			case 5:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//system("cls");
				printf("Insira o numero a ser SUBSTITUIDO:\n ");
				scanf("%d", &v);
				printf("Insira o numero SUBSTITUTO:\n");
				scanf("%d", &g);
				alterarValor(inicio, fim, v, g);
				break;
			case 6:
				removerLista(&inicio, &fim);
				break;
			case 7:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//system("cls");
				printf("%s\n", "Insira o numero a ser removido");
				scanf("%d", &v);
				removerPrimeiraOcorrencia(&inicio, &fim, v);
				break;
			case 0:
				return 0;
			default:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//system("cls");
				printf("Opcao invalida!\n");
				pause();
				break;
		}
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
					((*Inicio)->prox) = NULL;
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

void pause(){
	fflush(stdin);
	printf("Preciona qualquer tecla para continuar. . .\n");
	getchar();
}
