//Igor da Silva Rodrigues
//26/11/20
#include <stdio.h>
#include <stdlib.h>



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
void loadFrom(FILE* fp, Celula** Inicio, Celula** Fim);
void saveTo(FILE* fp, Celula* Inicio);
void pause();


FILE* file;
int main(){
	Celula *p;
	char a;
	int opcao, v, g;


	file = fopen("Lista_Duplamente_Encadeada_Circular.txt", "r");
	if (file != NULL){
		//todo load;
		loadFrom(file, &inicio, &fim);
		fim = inicio->prev;
	}
	fclose(file);
	
	while(1){
		//system("cls");
		printf("1- Imprimir do Inicio\n2- Imprimir do final\n3- Inserir no Inicio\n4- Inserir no Fim\n5- Alterar um valor\n6- Apagar a lista\n7- Apagar um valor\n0- Salvar e Sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				system("cls");
				imprimirInicio(inicio);
				pause();
				break;
			case 2:
				system("cls");
				imprimirFim(fim);
				pause();
				break;
			case 3:
				system("cls");
				printf("Insira o numero a ser inserido: ");
				scanf("%d", &v);
				inserirInicio(&inicio, &fim, v);
				break;
			case 4:
				system("cls");
				printf("Insira o numero a ser inserido: ");
				scanf("%d", &v);
				inserirFim(&inicio, &fim, v);
				break;
			case 5:
				system("cls");
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
				system("cls");
				printf("%s\n", "Insira o numero a ser removido");
				scanf("%d", &v);
				removerPrimeiraOcorrencia(&inicio, &fim, v);
				break;
			case 0:
				file = fopen("Lista_Duplamente_Encadeada_Circular.txt", "w");
				saveTo(file, inicio);
				fclose(file);
				return 0;
			default:
				system("cls");
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
		(*Inicio) = novaCelula;
		(*Fim) = novaCelula;
		novaCelula->prev = (*Fim);
		novaCelula->prox = (*Inicio);
	}else{
		(*Inicio)->prev = novaCelula;
		novaCelula->prox = (*Inicio);
		novaCelula->prev = (*Fim);
		(*Fim)->prox = novaCelula;
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
		(*Inicio)->prev = novaCelula;
		novaCelula->prox = (*Inicio);
		novaCelula->prev = (*Fim);
		(*Fim)->prox = novaCelula;
		(*Fim) = novaCelula;
	}
}

void imprimirInicio(Celula *Inicio){
	Celula* aux;
	if (Inicio != NULL){
		aux = Inicio;
		do{
			printf("%d\n", aux->dado);
			aux = aux->prox;
		}while (Inicio != aux);
	}
}

void imprimirFim(Celula *Fim){
	Celula* aux;
	if (Fim != NULL){
		aux = Fim;
		do{
			printf("%d\n", aux->dado);
			aux = aux->prev;
		}while (Fim != aux);
	}
}

Celula* buscar(Celula *Inicio, Celula *Fim, int val){

	if (Inicio != NULL && Fim != NULL){
		//while (Inicio != NULL && Fim != NULL){
		do{
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
		}while (!(Inicio->prev == Fim || Fim->prox == Inicio));

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
		while ((*Inicio)->prev != (*Fim)){
			(*Inicio) = (*Inicio)->prev;
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

void removerPrimeiraOcorrencia(Celula **Inicio, Celula **Fim, int val){
	Celula *aux;
	if ((*Inicio)!= NULL){
		while ((*Inicio)->prev != (*Fim)){ //posiciona o inicio ao inicio da lista;
			(*Inicio) = (*Inicio)->prev;
		}
		aux = (*Inicio);
		if (aux->prox == aux){ 
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
				aux->prev->prox = aux->prox;
				aux->prox->prev = aux->prev;
				if (aux == (*Fim)){
					(*Fim) = aux->prev;
				}else if (aux == (*Inicio)){
					(*Inicio) = aux->prox;
				}
				delete(aux);
				aux = NULL;
			}				
		}
	}else{
		printf("%s\n", "LISTA NAO INICIALIZADA!\n");
		pause();
	}
}

void loadFrom(FILE* fp, Celula** Inicio, Celula** Fim){

	int val;
	if (fp != NULL){
		while(!feof(fp)){
			fscanf(fp, ",%d", &val);
			inserirFim(Inicio, Fim, val);
		}
	}
}

void saveTo(FILE* fp, Celula* Inicio){
	Celula* aux;
	if (Inicio != NULL){
		aux = Inicio;
		do{
			fprintf(fp, ",%d", aux->dado);
			aux = aux->prox;
		}while (aux != inicio);
	}
}

void pause(){
	fflush(stdin);
	printf("Preciona qualquer tecla para continuar. . .\n");
	getchar();
}
