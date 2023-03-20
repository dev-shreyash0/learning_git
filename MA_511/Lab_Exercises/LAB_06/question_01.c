#include <stdio.h>

void reverse( char * ) ;

int main( void ){

	char A[1001] ;
	printf("Enter the string :: ");
	scanf("%[^\n]",A);

	reverse(A) ;

	printf("Reverse of the string is :: %s\n",A);

	return 0 ;

}

void reverse( char * A ){

	int lenA = 0 ;
	while( A[lenA] != '\0' ){
		lenA++ ;
	}

	int sI = 0 , eI = lenA-1 ;

	while( sI < eI ){
		char temp = A[sI] ;
		A[sI] = A[eI] ;
		A[eI] = temp ;
		sI++ ;
		eI-- ;
	}
	
	return ;

}
