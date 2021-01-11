#include <stdio.h>
int main(){
  int alvo;
  int multiplicador;
  for (multiplicador=1;multiplicador<=10;multiplicador++){
  	for (alvo=1;alvo<=10;alvo++){
  		printf("  %d X %d = %d\n",alvo, multiplicador, alvo*multiplicador);
	  }
	    }
}
