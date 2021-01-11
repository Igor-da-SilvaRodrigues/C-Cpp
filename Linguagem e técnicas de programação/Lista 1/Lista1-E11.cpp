#include<stdio.h>

int main(){
	 
 int a ,b,aux;
 
 printf("digite valores para a e b respectivamente: ");
 scanf("%d %d", &a,&b);
 
	 aux=a;
	 a=b;
	 b = aux;
	 
 printf("o valor de a eh = %d\n",a);	
  printf("o valor de b eh = %d\n",b);
		
	return 0;
}
