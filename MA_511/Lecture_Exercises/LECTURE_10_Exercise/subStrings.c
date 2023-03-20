#include <stdio.h>

int main(void){

	char S[1001] ;
	printf("Enter the string upto length 1000 :: ");
	scanf("%s",S);

	int len = 0 ;

	while( S[len] != '\0' ){
	
		len++ ;
	
	}

	for( int i = 0 ; i < len ; i++ ){
		for( int j = i ; j < len ; j++ ){
		
			for( int k = i ; k <= j ; k++ ){
				printf("%c",S[k]);
			}	
			printf("\n");		
		
		}
	}


}
