#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
	char stringa[50], stringb[50], stretornoa[50],stretornob[50], varaux;
	int tama, tamb, contadora,contadorb;
	
	printf("Insira a frase A\n");
	gets(stringa);
	printf("Insira a frase B\n");
	gets(stringb);
	
	
    tama=strlen(stringa)-1;
    tamb=strlen(stringb)-1;
    
    for (contadora=0, contadorb=tama ; contadora<=tama ; contadora++, contadorb--){
    	varaux=stringa[contadora];
    	stretornoa[contadorb]=varaux;
	}    	
	
	for (contadora=0, contadorb=tamb ; contadora<=tamb ; contadora++, contadorb--){
    	varaux=stringb[contadora];
    	stretornob[contadorb]=varaux;
	}    	
	
	for (contadora=0;contadora<=tama;contadora++){
		if (stretornoa[contadora]=='a' || stretornoa[contadora]=='A'){
			stretornoa[contadora]='*';
		}
	}
	
	for (contadora=0;contadora<=tamb;contadora++){
		if (stretornob[contadora]=='a' || stretornob[contadora]=='A'){
			stretornob[contadora]='*';
		}
	}
	
	
	printf("%s\n",stretornoa);
	printf("%s\n",stretornob);

}
