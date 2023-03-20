#include <stdio.h>

int main(void){

	char S[1000000] ;

	printf("Enter a String :: ");
	scanf("%[^\n]",S);

	int length = 0 ;

	while( S[length] != '\0' ){
	
		length++ ;
	
	}

	printf("%d\n",length);

	return 0 ;

}
