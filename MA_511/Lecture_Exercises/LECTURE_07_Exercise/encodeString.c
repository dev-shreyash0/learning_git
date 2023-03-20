#include <stdio.h>

int main(void){

	char S[1001] ;

	printf("Enter the string of alphabets of length upto 1000 :: ");
	scanf("%s",S);

	int sI = 0 ;

	int encode[1001] ;

	while( S[sI] != '\0' ){
	
		if( S[sI] >= 'A' && S[sI] <= 'Z' ){
		
			encode[sI] = (int)S[sI] - (int)'A' + 1  ;
		
		} else{
		
			encode[sI] = (int)S[sI] - (int)'a' + 1 ;
		
		}

		sI++ ;
	
	}

	encode[sI] = 100 ;

	int i = 0 ;

	while( encode[i] != 100 ){
	
		printf("%d ",encode[i]);
		i++ ;

	}

	printf("\n");

	return 0 ;

}
