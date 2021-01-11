#include <stdio.h>
int main(){
	float lado, bmenor, bmaior, altura,potencia,i, auxiliar;
	int operacao;
	
	printf("Insira a operação desejada\n 1-AREA DO QUADRADO\n 2- AREA DO RETANGULO\n 3- AREA DO TRAPEZIO\n 4-POTENCIACAO\n");
	scanf("%d",&operacao);
	switch (operacao){
		case 1:
			printf("Insira o valor do lado\n");
			scanf("%f",&lado);
		    lado=lado*lado;
		    printf("A area do quadrado e igual a: %f",lado);
		    break;
			
		case 2:
			printf("Insira o valor do lado\n");
			scanf("%f",&lado);
			printf("Insira o valor da altura\n");
			scanf("%f",&altura);
			lado=lado*altura;
			printf("A area do retangulo e igual a: %f", lado);
			break;
		case 3:
			printf("Insira o valor das bases seguida da altura");
			scanf("%f %f %f",&bmaior,&bmenor,&altura);
			lado=((bmaior+bmenor)*altura)/2;
			printf("a Area do trapezio e igual a: %f",lado);
			break;
									           //((B+b)*altura)/2
		case 4:
			printf("Insira o numero seguido da potencia\n");
			scanf("%f %f",&lado, &potencia);
			auxiliar=lado;
			if (potencia==0){
				lado=1;
			}
			else{
				for (i=1;i<potencia;i++){
					lado=lado*auxiliar;
					
				}
				
			}
			printf("O resulado de %f elevado a %f e %f ",auxiliar, potencia, lado);
			break;
		default:
			printf("ta errado");
			break;
	}
}
