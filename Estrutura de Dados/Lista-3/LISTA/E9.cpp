#include <stdio.h>
#include <stdlib.h>
typedef struct ListaS{ 
	int info; 
	struct ListaS *prox; 
}Celula; 

void inserirNoInicio(Celula** inicio, int valor);
void inserirNoFinal(Celula** inicio, int valor);
Celula* buscarCelula(int alvo, Celula* inicio);
void deletarLista(Celula** inicio);
void deletarNo(Celula** prevCel, int valor);
int contCel(Celula* inicio);
Celula* copiarLista(Celula* inicio);
Celula* intercalarListasOrdenadasCrescente(Celula* inicio_A, Celula* inicio_B);
void pause();

int main(){
	pause();
	return 0;
}

Celula* intercalarListasOrdenadasCrescente(Celula* inicio_A, Celula* inicio_B){
	Celula* inicio_Res = NULL;

	Celula* aux_A;
	Celula* aux_B;

	if (inicio_A == NULL){
		inicio_Res = inicio_B; //se a lista A estiver vazia, a lista B é retornada
							   //se a lista B estiver vazia, a lista A é retornada.
							   //Se ambas estiverem vazias, uma lista vazia é retornada.
	}else if (inicio_B == NULL){
		inicio_Res = inicio_A;
	}else{						//caso A e B forem não-vazias>
		aux_A = inicio_A;
		aux_B = inicio_B;

		if (aux_A->info <= aux_B->info){             //as primeiras casas de ambas as listas são adicionadas em ordem.
			inserirNoFinal(&inicio_Res, aux_A->info);
			inserirNoFinal(&inicio_Res, aux_B->info);
			aux_A = aux_A->prox;
			aux_B = aux_B->prox;
		}else{
			inserirNoFinal(&inicio_Res, aux_B->info);
			inserirNoFinal(&inicio_Res, aux_A->info);
			aux_B = aux_B->prox;
			aux_A = aux_A->prox;
		}
		while (aux_A != inicio_A || aux_B != inicio_B){ //enquanto uma das listas nao estiverem no final//termina quando ambas estiverem no final;

			if (aux_A != inicio_A && aux_B != inicio_B){//adiciona ordenadamente as casas quando ambas as filas ainda não terminaram
				if (aux_A->info <= aux_B->info){
					inserirNoFinal(&inicio_Res, aux_A->info);
					aux_A = aux_A->prox;
				}else{
					inserirNoFinal(&inicio_Res, aux_B->info);
					aux_B = aux_B->prox;
				}
			}else{// quando apenas uma estiver no final, insere o resto da outra fila 
				if (aux_A != inicio_A){
					inserirNoFinal(&inicio_Res, aux_A->info);
					aux_A = aux_A->prox;
				}
				if (aux_B != inicio_B){
					inserirNoFinal(&inicio_Res, aux_B->info);
					aux_B = aux_B->prox;
				}
			}
		}

	}
	return inicio_Res;
}

Celula* copiarLista(Celula* inicio){
	Celula* Res;
	Celula* aux;
	aux = inicio;
	do{
		inserirNoFinal(&Res, aux->info);
		aux = aux->prox;
	}while (aux != inicio);

	return Res;
}

int contCel(Celula* inicio){
	int cont = 0;
	
	Celula* aux = inicio;
	do{
		cont++;
		aux = aux->prox;
	}while (aux != inicio);

	return cont + 1;
}

void deletarNo(Celula** inicio, int valor){ 
	Celula *prevCel;                        
	Celula *currentCel;
	if ((*inicio) == NULL){
		printf("Lista nao inicializada\n");
		pause();
	}else{
		prevCel = (*inicio);
		currentCel = prevCel->prox;
		if (currentCel == prevCel){
			if (currentCel->info == valor){
				deletarLista(inicio);
			}
		}else{
			while (currentCel != (*inicio) && currentCel->info != valor){
				prevCel = currentCel;
				currentCel = currentCel->prox;	
			}
			
			if (currentCel->info == valor){
				prevCel->prox = currentCel->prox;
				if (currentCel == (*inicio)){
					(*inicio) = prevCel;
				}
				delete(currentCel);
			}
		}
	}
}

void deletarLista(Celula** inicio){
	if ((*inicio) != NULL){//...................................Se a lista e nÃ£o-nula;
		Celula* nextCel = (*inicio)->prox;//.....NextCel recebe a segunda celula da lista, seja ela nula ou nÃ£o;
		if (nextCel == (*inicio)){//.................................Se a lista sÃ³ pussui uma casa nÃ£o hÃ¡ como avanÃ§ar com o nextCel
			delete((*inicio));//..................................portanto, apenas deleta-se a unica casa da lista, e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}else{//................................................Se a lista possui duas ou mais casas
			Celula* aux = (*inicio);
			while (aux->prox != (*inicio)){
				aux = aux->prox;
			}
			
			do{//...............................................libera-se o ponteiro, e ambos andam uma casa atÃ© que o inicio esteja no final da fila (nÃ£o pode mais avanÃ§ar);
				delete((*inicio));
				(*inicio) = nextCel;
				nextCel = nextCel->prox;
			}while ((*inicio) != aux);
			delete((*inicio));//..................................libera-se a ultima casa sobrando e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}
		
	}
}

Celula* buscarCelula(int alvo, Celula* inicio){
	Celula* aux;
	if (inicio != NULL){
		aux = inicio;
		do{
			if (inicio->info == alvo){
				return inicio;
			}
			inicio = inicio->prox;
		}while (inicio != aux);
		
	}
	return NULL;
}


void inserirNoInicio(Celula** inicio, int valor){//done
	Celula* novaCelula;
	Celula* aux;
	novaCelula = new Celula();
	novaCelula->info = valor;
	novaCelula->prox = (*inicio);
	
	if ((*inicio) == NULL){
		novaCelula->prox = novaCelula;
	}else{
		aux = (*inicio);
		while(aux->prox != (*inicio)){
			aux = aux->prox;
		}
		aux->prox = novaCelula;
	}
	(*inicio) = novaCelula;
}

void inserirNoFinal(Celula** inicio, int valor){//done
	//inserirNoInicio(valor, inicio);
	
	Celula* novaCelula;
	Celula* aux;
	if ((*inicio) == NULL){
		inserirNoInicio(inicio, valor);
	}else{
		novaCelula = new Celula();
		novaCelula->info = valor;
		novaCelula->prox = (*inicio);
		aux = (*inicio);
		while (aux->prox != (*inicio)){
			aux = aux->prox;
		}
		aux->prox = novaCelula;
	}
}

void pause(){
	fflush(stdin);
	printf("Preciona qualquer tecla para continuar. . .\n");
	getchar();
}
