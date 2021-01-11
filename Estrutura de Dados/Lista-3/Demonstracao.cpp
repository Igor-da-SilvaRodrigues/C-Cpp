
#include <stdio.h>
#include <stdlib.h>

typedef struct celulaLista {
		int dado;
		struct celulaLista *proxCel;
		
	}CelulaLista;
	


void inserirNoInicio(int valor, CelulaLista **inicio);
void inserirNoFinal(int valor, CelulaLista **inicio);
void deletarLista(CelulaLista **inicio);
void deletarNo(CelulaLista **prevCel, int valor);
void exibirListaApos(CelulaLista *inicio);
void modificarCelulas(CelulaLista *inicio, int old, int val);
void modificarPrimeiraOcorrencia(CelulaLista *inicio, int old, int val);
CelulaLista* buscarCelula(int alvo, CelulaLista *inicio);

CelulaLista* copiar(CelulaLista* alvo);
CelulaLista* concatena(CelulaLista* L1, CelulaLista* L2); 
CelulaLista* toLista(int vetor[], int tam);
void deletarPrimeiroNo(CelulaLista** inicio);
CelulaLista* deletarLista(CelulaLista** inicio, unsigned int n);
CelulaLista* quebrarLista(CelulaLista* inicio, int n);
int contCel(CelulaLista* Inicio);
void inverterLista(CelulaLista** inicio);

CelulaLista *Inicio_Lista_Simples;
CelulaLista *Lista_Simples_B;
CelulaLista *teste_Lista_Simples;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct ListaD{
	struct ListaD* prev;
	struct ListaD* prox;
	int dado;
}ListaD;

ListaD* Inicio_Lista_Duplamente = NULL;
ListaD* Fim_Lista_Duplamente = NULL;

ListaD* Inicio_Lista_Duplamente_B = NULL;
ListaD* Fim_Lista_Duplamente_B = NULL;

void inserirInicio(ListaD** Inicio, ListaD** Fim, int val);
void inserirFim(ListaD** Inicio, ListaD** Fim, int val);
void imprimirInicio(ListaD *Inicio);
void imprimirFim(ListaD *Fim);
ListaD* buscar(ListaD *Inicio, ListaD *Fim, int val);
void alterarValor(ListaD *Inicio, ListaD *Fim, int val, int substituto);
void removerLista(ListaD **Inicio, ListaD **Fim);
void removerPrimeiraOcorrencia(ListaD **Inicio, ListaD **Fim, int val);
void pause();

ListaD* concatenar(ListaD** inicioA,ListaD** fimA, ListaD* inicioB,ListaD* fimB);
void quebrarLista(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B, int v);
void intercalarListas(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B);
void intercalarListasOrdenadasCrescente(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B);


int main(){
	Inicio_Lista_Simples = NULL;
	Lista_Simples_B = NULL;
	teste_Lista_Simples = NULL;
	CelulaLista* aux = NULL;
	int v, old, opcao, opcao2;
	int array[] = {1, 2, 3, 4, 5};
	
	do{
		printf("1- Lista simplesmente encadeada\n2- Lista duplamente encadeada\n");
		scanf("%d", &opcao2);
	}while (opcao2 != 1 && opcao2 != 2);

	switch(opcao2){
		case 1:
				
			while (1){
				system("cls");
				printf("\n1-Inserir uma nova celula na lista A\n2-Exibir a Lista A\n\n3- exibir copia da lista A\n\
4- Inserir uma nova celula na lista B\n5- Concatenar A & B (A = A + B)\n6- passar vetor para lista e exibir\n\
7- Apagar a primeira celula de A\n8- Apagar n celulas do inicio de A\n9- quebrar a lista A em duas listas na primeira ocorrencia de n\n\
10- Contar numero de casas em A\n11- Inverter lista A\n");
				scanf("%d", &opcao);
				switch(opcao){
					case 1://Inserir uma nova celula no inicio
						system("cls");
						printf("Insira um valor\n");
						scanf("%d", &v);
						inserirNoInicio(v, &Inicio_Lista_Simples);
						break;
					case 2://Exibir a Lista
						system("cls");
						exibirListaApos(Inicio_Lista_Simples);
						
						system("pause");
						break;
					case 3:
						system("cls");
						aux = copiar(Inicio_Lista_Simples);
						exibirListaApos(aux);
						system("pause");
						break;
					case 4:
						system("cls");
						printf("Insira um valor\n");
						scanf("%d", &v);
						inserirNoInicio(v, &Lista_Simples_B);
						break;
						
						
					case 5:
						system("cls");
						Inicio_Lista_Simples = concatena(Lista_Simples_B, Inicio_Lista_Simples);// Inicio + ListaB
					break;	
					
					case 6:
						
						system("cls");
						for (int idaw = 0; idaw < sizeof(array)/sizeof(array[0]); idaw++){
							printf("%d\n", array[idaw]);
						}
						printf("size = %d\n", sizeof(array)/sizeof(array[0]));
						printf("---\n");
						
						teste_Lista_Simples = toLista(array, sizeof(array)/sizeof(array[0]));
						exibirListaApos(teste_Lista_Simples);
						system("pause");
						break;
					
					case 7:
						deletarPrimeiroNo(&Inicio_Lista_Simples);
						break;
						
					case 8:
						system("cls");
						do{
						printf("Insira quantas casas deseja deletar: \n");
						scanf("%d", &v);
						}while (v < 0);
						
						deletarLista(&Inicio_Lista_Simples, v);
						break;
					case 9:
						system("cls");
						printf("Insira o valor no qual a quebra deve acontecer: \n");
						scanf("%d", &v);
						teste_Lista_Simples = quebrarLista(Inicio_Lista_Simples, v);
						printf("Lista A> \n");
						exibirListaApos(Inicio_Lista_Simples);
						printf("Lista C> \n");
						exibirListaApos(teste_Lista_Simples);
						system("pause");
					break;
					case 10:
						system("cls");
						v = contCel(Inicio_Lista_Simples);
						printf("%d\n", v);
						pause();
						break;
					case 11:
						inverterLista(&Inicio_Lista_Simples);
						break;
					default:
						
						return(0);
					break;
				}
			}		
				break;
				
				
			case 2:
				
				while (1){
					system("cls");
					printf("1- Imprimir A do Inicio\n2- Inserir no Inicio de A\n3- Inserir Fim de A\n4- Imprimir B do Inicio\n5- Inserir no Inicio de B\n\
6- Concatenar A e B\n7- Quebrar lista A\n8- intercalar listas A e B (armazena em A)\n0- Sair\n");
					scanf("%d", &opcao);
					switch(opcao){
						case 1:
							system("cls");
							imprimirInicio(Inicio_Lista_Duplamente);
							pause();
							break;
						case 2:
							system("cls");
							printf("Insira o numero a ser inserido: ");
							scanf("%d", &v);
							inserirInicio(&Inicio_Lista_Duplamente, &Fim_Lista_Duplamente, v);
							break;
						case 3:
							system("cls");
							printf("Insira o numero a ser inserido: ");
							scanf("%d", &v);
							inserirFim(&Inicio_Lista_Duplamente, &Fim_Lista_Duplamente, v);
							break;
						case 4:
							system("cls");
							imprimirInicio(Inicio_Lista_Duplamente_B);
							pause();
							break;
						case 5:
							system("cls");
							printf("Insira o numero a ser inserido: ");
							scanf("%d", &v);
							inserirInicio(&Inicio_Lista_Duplamente_B, &Fim_Lista_Duplamente_B, v);
							break;
						case 6:
							Inicio_Lista_Duplamente = concatenar(&Inicio_Lista_Duplamente, &Fim_Lista_Duplamente, Inicio_Lista_Duplamente_B, Fim_Lista_Duplamente_B);
							
							break;
						case 7:
							system("cls");
							printf("Insira o valor no qual a quebra deve acontecer: \n");
							scanf("%d", &v);
							quebrarLista(&Inicio_Lista_Duplamente, &Fim_Lista_Duplamente, &Inicio_Lista_Duplamente_B, &Fim_Lista_Duplamente_B, v);
							printf("Lista A> \n");
							imprimirInicio(Inicio_Lista_Duplamente);
							printf("Lista B> \n");
							imprimirInicio(Inicio_Lista_Duplamente_B);
							system("pause");
							break;
						case 8:
							intercalarListas(&Inicio_Lista_Duplamente, &Fim_Lista_Duplamente, &Inicio_Lista_Duplamente_B, &Fim_Lista_Duplamente_B);
							break;
							
						case 0:
							return 0;
						default:
							system("cls");
							printf("Opcao invalida!\n");
							pause();
							break;
					}
				}
			break;
	}
		
return 0;
}

void inverterLista(CelulaLista** inicio){
	CelulaLista* aux_a;
	CelulaLista* aux_b;
	CelulaLista* aux_c = NULL;

	if ((*inicio) != NULL){
		aux_b = (*inicio);
		aux_a = aux_b->proxCel;
		while (aux_a != NULL){
			aux_b->proxCel = aux_c;
			aux_c = aux_b;
			aux_b = aux_a;
			aux_a = aux_a->proxCel;
		}
		aux_b->proxCel = aux_c;
		(*inicio) = aux_b;
	}
}

int contCel(CelulaLista* Inicio){
	int cont = 0;
	CelulaLista* aux;
	if (Inicio != NULL){
		aux = Inicio;
		while (aux != NULL){
			cont++;
			aux = aux->proxCel;
		}
	}
	return cont;
}

CelulaLista* quebrarLista(CelulaLista* inicio, int n){
	CelulaLista* aux;
	CelulaLista* Lista2;
	if (inicio != NULL){
		aux = inicio;
		while (aux != NULL && aux->dado != n){
			aux = aux->proxCel;
		}
		if (aux != NULL){
			Lista2 = aux->proxCel;
			aux->proxCel = NULL;
			return Lista2;
		}
	}
	return NULL;
}


CelulaLista* deletarLista(CelulaLista** inicio, unsigned int n){
	for (int i = 0; i<n; i++ ){
		deletarPrimeiroNo(inicio);
	}
	return (*inicio);
}


void deletarPrimeiroNo(CelulaLista** inicio){
	CelulaLista* aux;
	if ((*inicio) != NULL){
		aux = (*inicio)->proxCel;
		delete((*inicio));
		(*inicio) = aux;
	}
}

CelulaLista* toLista(int vetor[], int tam){
	printf("size = %d\n", tam);
	CelulaLista* inicio = NULL;
	if (tam == 0){
		return NULL;
	}else{
		for(int i = 0; i < tam; i++){
			inserirNoFinal(vetor[i], &inicio);
		}
		return inicio;
	}
	
}

CelulaLista* concatena(CelulaLista* L1, CelulaLista* L2){// concatena L1 em L2 e retorna L2 + L1;
	CelulaLista* aux;
	aux = L1;
	while (aux != NULL){
		inserirNoFinal(aux->dado, &L2);
		aux = aux->proxCel;
	}
	return L2;
}

CelulaLista* copiar(CelulaLista* alvo){
	CelulaLista* Inicio = NULL;
	
	while (alvo != NULL){
		inserirNoFinal(alvo->dado, &Inicio);
		alvo = alvo->proxCel;
	}
	
	return Inicio;
}


void inserirNoInicio(int valor, CelulaLista **inicio){
	CelulaLista *novaCelula;
	//novaCelula = new celulaLista();
	novaCelula = new CelulaLista();
		novaCelula->dado = valor;
		novaCelula->proxCel = (*inicio);
		(*inicio) = novaCelula;
}

void inserirNoFinal(int valor, CelulaLista **inicio){
	CelulaLista *novaCelula;
	if ((*inicio) != NULL){
		CelulaLista *aux = (*inicio);
		while ( aux->proxCel != NULL){
			aux = aux->proxCel;
		}
		novaCelula = new CelulaLista();
		novaCelula->dado = valor;
		novaCelula->proxCel = aux->proxCel;
		aux->proxCel = novaCelula;
		
	}else{
		novaCelula = new CelulaLista();
		novaCelula->dado = valor;
		novaCelula->proxCel = (*inicio);
		(*inicio) = novaCelula;
	}
}

void deletarLista(CelulaLista **inicio){
	if ((*inicio) != NULL){//...................................Se a lista e não-nula;
		CelulaLista *nextCel = (*inicio)->proxCel;//.....NextCel recebe a segunda celula da lista, seja ela nula ou não;
		if (nextCel == NULL){//.................................Se a lista só pussui uma casa não há como avançar com o nextCel
			delete((*inicio));//..................................portanto, apenas deleta-se a unica casa da lista, e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}else{//................................................Se a lista possui duas ou mais casas
			do{//...............................................libera-se o ponteiro, e ambos andam uma casa até que o nextCel seja nulo (não pode mais avançar);
				delete((*inicio));
				(*inicio) = nextCel;
				nextCel = nextCel->proxCel;
			}while (nextCel != NULL);
			delete((*inicio));//..................................libera-se a ultima casa sobrando e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}
		
	}
}

void deletarNo(CelulaLista **inicio, int valor){ //comentar a linha A e "descomentar" a linha B para deletar apenas a primeira ocorrência
	CelulaLista *prevCel;                        //comentar a linha B e "descomentar" a linha A para deletar todas as ocorrências
	CelulaLista *currentCel;
	int cont = 0;
	if ((*inicio) == NULL){
		printf("Lista nao inicializada\n");
		system("pause");
	}else{
		prevCel = (*inicio);
		currentCel = (*inicio)->proxCel;
		if(currentCel == NULL ){			
			if (valor == prevCel->dado){
				(*inicio) = currentCel;
				delete(prevCel);
			}
		}else{
			if (valor == prevCel->dado){
				(*inicio) = currentCel;
				delete(prevCel);
				prevCel = currentCel;
				currentCel = currentCel->proxCel;
				//deletarNo(&(*inicio), valor);   //linha A
			} else{
				while (currentCel != NULL){
					if (valor == currentCel->dado){
						prevCel->proxCel = currentCel->proxCel;
						delete(currentCel);
						currentCel = prevCel->proxCel;
						break;                            //linha B
					}else{
						prevCel = currentCel;
						currentCel = currentCel->proxCel;
					}	
				}		
			}
		}
	}
}

void exibirListaApos(CelulaLista *inicio){
	CelulaLista *currentCel = inicio;
	
	while (currentCel != NULL){
		printf("%d\n", currentCel->dado);
		currentCel = currentCel->proxCel;
	}
	
}

void modificarCelulas(CelulaLista *inicio, int old, int val){
	if (inicio != NULL){
		//celulaLista *nextCel = inicio->proxCel;
		while (inicio != NULL){
			if (inicio->dado == old){
				inicio->dado = val;
			}
			inicio = inicio->proxCel;
		}
	}
}

void modificarPrimeiraOcorrencia(CelulaLista *inicio, int old, int val){
		//celulaLista *nextCel = inicio->proxCel;
		//while (inicio != NULL && inicio->dado != old){
		//	inicio = inicio->proxCel;
		//}
		inicio = buscarCelula(old, inicio);
		if (inicio != NULL){
			inicio->dado = val;	
		}
		else{
			printf("Valor nao encontrado\n");
		}
}

CelulaLista* buscarCelula(int alvo, CelulaLista *inicio){
	if (inicio != NULL){
		while (inicio != NULL){
			if (inicio->dado == alvo){
				return inicio;
			}
			inicio = inicio->proxCel;
		}
		
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void intercalarListas(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B){// intercala duas listas
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
				inserirFim(&Inicio_C, &Fim_C, aux_A->dado);
				aux_A = aux_A->prox;
			}
			if (aux_B != NULL){
				inserirFim(&Inicio_C, &Fim_C, aux_B->dado);
				aux_B = aux_B->prox;
			}	
		
		}
		
		(*Inicio_A) = Inicio_C;
		(*Fim_A) = Fim_C;
	}
}



void intercalarListasOrdenadasCrescente(ListaD** Inicio_A, ListaD** Fim_A, ListaD** Inicio_B, ListaD** Fim_B){// Intercala duas listas ordenadas
																											  // na ordem crescente em uma
																										      //lista ordenada crescente
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
		
		while (aux_A != NULL || aux_B != NULL){
			
			if (aux_A != NULL && aux_B != NULL){
				
				if (aux_A->dado <= aux_B->dado){
					inserirFim(&Inicio_C, &Fim_C, aux_A->dado);
					aux_A = aux_A->prox;
				}else{
					inserirFim(&Inicio_C, &Fim_C, aux_B->dado);
					aux_B = aux_B->prox;
				}

			}else{
				if (aux_A != NULL){
					inserirFim(&Inicio_C, &Fim_C, aux_A->dado);
					aux_A = aux_A->prox;
				}
				
				if (aux_B != NULL){
					inserirFim(&Inicio_C, &Fim_C, aux_B->dado);
					aux_B = aux_B->prox;
				}
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
		while (aux != NULL && aux->dado != v){
			aux = aux->prox;
		}
		if (aux != NULL){
			(*Fim_B) = (*Fim_A);
			(*Fim_A) = aux;
			(*Inicio_B) = aux->prox;
			aux->prox = NULL;
			(*Inicio_B)->prev = NULL;
			
		}
	}
	
}


ListaD* concatenar(ListaD** inicioA,ListaD** fimA, ListaD* inicioB,ListaD* fimB){// concatena B no final de A (retorna A+B);
	ListaD* aux;
	aux = inicioB;
	while (aux != NULL){
		inserirFim(inicioA, fimA, aux->dado);
		aux = aux->prox;
	}
	return (*inicioA);
} 


void inserirInicio(ListaD** Inicio, ListaD** Fim, int val){
	
	ListaD* novaListaD;
	//novaListaD = malloc(sizeof(ListaD));
	novaListaD = new ListaD();
	novaListaD->dado = val;
	if ((*Inicio) == NULL){
		novaListaD->prev = (*Inicio);
		novaListaD->prox = (*Fim);
		(*Inicio) = novaListaD;
		(*Fim) = novaListaD;
	}else{
		novaListaD->prev = (*Inicio)->prev;
		novaListaD->prox = (*Inicio); 
		(*Inicio)->prev = novaListaD;
		(*Inicio) = novaListaD;
	}
	
}

void inserirFim(ListaD** Inicio, ListaD** Fim, int val){
	ListaD *novaListaD;
	if ((*Fim) == NULL){
		inserirInicio(Inicio, Fim, val);
		
	}else{
		novaListaD = new ListaD();
		novaListaD->dado = val;
		novaListaD->prev = (*Fim);
		novaListaD->prox = (*Fim)->prox;
		(*Fim)->prox = novaListaD;
		(*Fim) = novaListaD;
	}
}

void imprimirInicio(ListaD *Inicio){
	while (Inicio != NULL){
		printf("%d\n", Inicio->dado);
		Inicio = Inicio->prox;
	}
}

void imprimirFim(ListaD *Fim){
	while (Fim != NULL){
		printf("%d\n", Fim->dado);
		Fim = Fim->prev;
	}
}

ListaD* buscar(ListaD *Inicio, ListaD *Fim, int val){

	if (Inicio != NULL && Fim != NULL){
		while (Inicio != NULL && Fim != NULL){
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
	}
	return NULL;
}

void alterarValor(ListaD *Inicio, ListaD *Fim, int val, int substituto){
	ListaD *aux = buscar(Inicio, Fim, val);
	if (aux == NULL){
		printf("VALOR NAO ENCONTRADO!\n");
		pause();
	}else{
		aux->dado = substituto;
	}
}

void removerLista(ListaD **Inicio, ListaD **Fim){
	ListaD *aux;
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

void removerPrimeiraOcorrencia(ListaD **Inicio, ListaD **Fim, int val){
	ListaD *aux;
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
