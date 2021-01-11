#include<stdio.h>

int main(){
	float metro,valor;
	char code;
	
	printf("Para converter de metros para Polegadas digite 'A'\n Para Pes DIGITE 'B'\n PARA JARDAS DIGITE 'C'\n PARA MILHAS 'D'\n PARA MILHAS NAUTICAS 'E' :");	
	scanf("%c",&code);
	
	printf("digite a metragem a ser convertida");
	scanf("%f",&metro);
	
	switch (code){
		case 'A':
			valor=metro*39.3701;
			printf("O valor em polegadas eh:%f",valor);break;
			case 'B':
				valor=metro*3.28084;
				printf("O VALOR EM PES EH =%f",valor);break;
				case 'C':
					valor=metro*1.09361;
					printf("O VALOR EM JARDAS EH =%f",valor);break;
					case 'D':
						valor=metro*0.00062;
						printf("O VALOR EM MILHAS EH= %f",valor);break;
						case 'E':
							valor=metro*0.00055;
							printf("O VALOR EM MILHAS NAUTICAS EH =%f",valor);break;
			
	}
	return 0;
}
