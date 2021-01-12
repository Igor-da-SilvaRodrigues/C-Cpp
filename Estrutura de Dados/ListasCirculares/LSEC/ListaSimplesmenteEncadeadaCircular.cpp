//Lista simplesmente encadeada circular.
//Igor da Silva Rodrigues
//26/11/20
#include <stdio.h>
#include <stdlib.h>

struct celulaLista {
		int dado;
		struct celulaLista *proxCel;
		
	};

void inserirNoInicio(int valor, struct celulaLista **inicio);
void inserirNoFinal(int valor, struct celulaLista **inicio);
void deletarLista(struct celulaLista **inicio);
void deletarNo(struct celulaLista **prevCel, int valor);
void exibirListaApos(struct celulaLista *inicio);
void modificarCelulas(struct celulaLista *inicio, int old, int val);
void modificarPrimeiraOcorrencia(struct celulaLista *inicio, int old, int val);
struct celulaLista* buscarCelula(int alvo, struct celulaLista *inicio);
struct celulaLista* loadFrom(FILE* fp);
void saveTo(FILE* fp, struct celulaLista* inicio);
void pause();

struct celulaLista *Inicio;
FILE* file;

int main(){
	Inicio = NULL;
	int v, old, opcao;
	file = fopen("Lista_Simplesmente_Encadeada_Circular.txt", "r");
	if (file != NULL){
		Inicio = loadFrom(file);
	}
	fclose(file);
	while (1){
	system("cls");
		printf("\n1-Inserir uma nova celula no inicio\n2-Inserir uma nova celula no final\n3-Exibir a Lista\n4-Deletar a lista\n5-Deletar um valor\n6-Modificar valores\n7-Modificar primeira ocorrencia\n0-Salvar e sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1://Inserir uma nova celula no inicio
				system("cls");
				printf("Insira um valor\n");
				scanf("%d", &v);
				inserirNoInicio(v, &Inicio);
				break;
			case 2://Inserir uma nova celula no final
				system("cls");
				printf("Insira um valor\n");
				scanf("%d", &v);
				inserirNoFinal(v, &Inicio);
				break;
			case 3://Exibir a Lista
				system("cls");
				exibirListaApos(Inicio);
				
				pause();
				break;
			case 4://Deletar a lista
				deletarLista(&Inicio);
				
				break;
			case 5://Deletar um valor
				system("cls");
				printf("Insira o valor a ser excluido\n");
				scanf("%d", &v);
				deletarNo(&Inicio, v);
				break;
			case 6://modificar valores
				system("cls");
				printf("Insira o valor a ser substituido\n");
				scanf("%d", &old);
				printf("Insira o novo valor\n");
				scanf("%d", &v);
				modificarCelulas(Inicio, old, v);
				break;
			case 7://modificar primeira ocorrencia
				system("cls");
				printf("Insira o valor a ser substituido\n");
				scanf("%d", &old);
				printf("Insira o novo valor\n");
				scanf("%d", &v);
				modificarPrimeiraOcorrencia(Inicio, old, v);
				break;
			case 0: 
				//todo salvar;
				file = fopen("Lista_Simplesmente_Encadeada_Circular.txt", "w");
				saveTo(file, Inicio);
				fclose(file);
				return 0;
				break;
			default:
				
				return(0);
			break;
		}
	}	
return 0;
}

void inserirNoInicio(int valor, struct celulaLista **inicio){//done
	struct celulaLista *novaCelula;
	struct celulaLista* aux;
	novaCelula = new celulaLista();
	novaCelula->dado = valor;
	novaCelula->proxCel = (*inicio);
	
	if ((*inicio) == NULL){
		novaCelula->proxCel = novaCelula;
	}else{
		aux = (*inicio);
		while(aux->proxCel != (*inicio)){
			aux = aux->proxCel;
		}
		aux->proxCel = novaCelula;
	}
	(*inicio) = novaCelula;
}

void inserirNoFinal(int valor, struct celulaLista **inicio){//done
	//inserirNoInicio(valor, inicio);
	
	struct celulaLista *novaCelula;
	struct celulaLista* aux;
	if ((*inicio) == NULL){
		inserirNoInicio(valor, inicio);
	}else{
		novaCelula = new celulaLista();
		novaCelula->dado = valor;
		novaCelula->proxCel = (*inicio);
		aux = (*inicio);
		while (aux->proxCel != (*inicio)){
			aux = aux->proxCel;
		}
		aux->proxCel = novaCelula;
	}
}

void deletarLista(struct celulaLista **inicio){
	if ((*inicio) != NULL){//...................................Se a lista e não-nula;
		struct celulaLista *nextCel = (*inicio)->proxCel;//.....NextCel recebe a segunda celula da lista, seja ela nula ou não;
		if (nextCel == (*inicio)){//.................................Se a lista só pussui uma casa não há como avançar com o nextCel
			delete((*inicio));//..................................portanto, apenas deleta-se a unica casa da lista, e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}else{//................................................Se a lista possui duas ou mais casas
			struct celulaLista* aux = (*inicio);
			while (aux->proxCel != (*inicio)){
				aux = aux->proxCel;
			}
			
			do{//...............................................libera-se o ponteiro, e ambos andam uma casa até que o inicio esteja no final da fila (não pode mais avançar);
				delete((*inicio));
				(*inicio) = nextCel;
				nextCel = nextCel->proxCel;
			}while ((*inicio) != aux);
			delete((*inicio));//..................................libera-se a ultima casa sobrando e seta o ponteiro como nulo;
			(*inicio) = NULL;
		}
		
	}
}

void deletarNo(struct celulaLista **inicio, int valor){ 
	struct celulaLista *prevCel;                        
	struct celulaLista *currentCel;
	//int cont = 0;
	if ((*inicio) == NULL){
		printf("Lista nao inicializada\n");
		pause();
	}else{
		prevCel = (*inicio);
		currentCel = prevCel->proxCel;
		if (currentCel == prevCel){
			if (currentCel->dado == valor){
				deletarLista(inicio);
			}
		}else{
			while (currentCel != (*inicio) && currentCel->dado != valor){
				prevCel = currentCel;
				currentCel = currentCel->proxCel;	
			}
			
			if (currentCel->dado == valor){
				prevCel->proxCel = currentCel->proxCel;
				if (currentCel == (*inicio)){
					(*inicio) = prevCel;
				}
				delete(currentCel);
			}
		}
	}
}

void exibirListaApos(struct celulaLista *inicio){
	struct celulaLista *currentCel = inicio;
	if (inicio != NULL){
	printf("-----\n");
	do{
		printf("%d\n", currentCel->dado);
		currentCel = currentCel->proxCel;
	}while (currentCel != inicio);
	printf("-----\n");
	}else{
		printf("Lista vazia!\n");
	}
	
}

void modificarCelulas(struct celulaLista *inicio, int old, int val){
	struct celulaLista* aux;
	if (inicio != NULL){
		aux = inicio;
		//celulaLista *nextCel = inicio->proxCel;
		do{
			if (inicio->dado == old){
				inicio->dado = val;
			}
			inicio = inicio->proxCel;
		}while (inicio != aux);
	}else{
		printf("Lista vazia!\n");
		pause();
	}
}

void modificarPrimeiraOcorrencia(struct celulaLista *inicio, int old, int val){
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
			pause();
		}
}

struct celulaLista* buscarCelula(int alvo, struct celulaLista *inicio){
	struct celulaLista* aux;
	if (inicio != NULL){
		aux = inicio;
		do{
			if (inicio->dado == alvo){
				return inicio;
			}
			inicio = inicio->proxCel;
		}while (inicio != aux);
		
	}
	//printf("toretornandonulo");
	//pause();
	return NULL;
}

struct celulaLista* loadFrom(FILE* fp){
	struct celulaLista* inicio;
	inicio = NULL;
	int val;
	if (fp != NULL){
		
		while(!feof(fp)){
			fscanf(fp, ",%d", &val);
			inserirNoFinal(val, &inicio);
		}
		return inicio;
	}else{
		return NULL;
	}
}

void saveTo(FILE* fp, struct celulaLista* inicio){
	struct celulaLista* aux;
	if (inicio != NULL){
		aux = inicio;
		do{
			fprintf(fp, ",%d", aux->dado);
			aux = aux->proxCel;
		}while (aux != inicio);
	}
}

void pause(){
	fflush(stdin);
	printf("Preciona qualquer tecla para continuar. . .\n");
	getchar();
}

