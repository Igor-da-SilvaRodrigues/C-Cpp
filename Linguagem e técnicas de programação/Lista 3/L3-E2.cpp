#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
     
    FILE *entrada;
    FILE *saida;
    char nome_entrada[40],nome_saida[40],cidade[40],nomelido[100],stringrecebida[100],stringrecebidb,maiorcidade[100];
    int ngente,tam,acumulador,contador,cont,conta,contb,contc=0,valorrecebido=0;
    int validador;
     
    printf("Insira o nome do arquivo de entrada...\n");
    scanf("%s",&nome_entrada);
    entrada =  fopen(nome_entrada,"a");    
     
    printf("Insira o nome do arquivo de saida...\n");
    scanf("%s",&nome_saida);
    saida = fopen(nome_saida,"w");
     
    do{
    printf("Deseja Inserir uma cidade no arquivo de entrada?");
    printf("\n1-sim\n");
    scanf("%d",&validador);
     
     
     
    if (validador==1){
        printf("\nNome_da_cidade Numero_de_habitantes\n");
        scanf ("%s %d",&cidade,&ngente);
        fprintf(entrada,"%s %d\n",cidade,ngente);  //insere cidades no arquivo
    }
    }while (validador==1);
     
    fclose(entrada);
    entrada=fopen(nome_entrada,"r");           // abre para leitura
     
    while(fgets(nomelido,100,entrada)!=NULL){
        tam=strlen(nomelido);                                                //lê o arquivo até ficar o fim, linha por linha, armazenando em 'nomelido'
        for (cont=0;cont<tam;cont++){
            if (nomelido[cont]==' '){                                        //percorre 'nomelido' até achar ' '
                 //contc++; 
                for (conta=cont+1,contb=0;conta<tam;conta++,contb++){
                    stringrecebida[contb]=nomelido[conta];
                }
                
                if (contc==1){
                	//strcpy(maiorcidade,stringrecebida);
                	strcpy(maiorcidade,nomelido);
                	acumulador=atoi(stringrecebida);
                	printf("Primeiro loop %s",&maiorcidade);
                	printf("--%d--",acumulador);
				}
				else if (atoi(stringrecebida)>acumulador){
					acumulador=atoi(stringrecebida);
					strcpy(maiorcidade,nomelido);
				}
                
                //val=atoi(str)
                
                
                
                //acumulador=stringrecebida[contb];
                //printf("\n%s",stringrecebida);
                
                
                
                
                
                /*if (fgets(stringrecebida,tam-cont,entrada) > valorrecebido ){
                    strcpy(stringrecebidb,stringrecebida);
                    valorrecebido=stringrecebidb
                     
                }*/
                 
                 
                 
                /*for (conta=cont;conta<tam;conta++){
                     
                }*/
                 
            }
        }
     
         
    }
     printf("\nstring:%s",maiorcidade);
     fprintf(saida,"%s",maiorcidade);
     
     
     
}
