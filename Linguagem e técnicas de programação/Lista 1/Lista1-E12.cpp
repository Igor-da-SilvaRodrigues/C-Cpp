#include<stdio.h>

int main() {
	
	int x;
	
	scanf("%d",&x);
	
	
	if (x%2==0) {
		printf("ele é divisivel por 2\n");
	}
	 if (x%3==0) {
		printf("ele é divisivel por 3\n");
	}
	 if (x%5==0) {
		printf("ele é divisivel por 5\n");
	}	
 if (x%10==0){
printf("divisivel por 10\n");
}
if (x % 10 != 0 && x % 5 != 0 && x % 3 != 0 && num % 2 !=0)  {
	printf("divisivel por nenhum destes\n");
}

	
	return 0;
}
