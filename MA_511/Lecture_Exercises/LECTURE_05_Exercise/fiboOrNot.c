#include <stdio.h>

int main(void){

	int N ;
	printf("Enter the value of N :: ");
	scanf("%d",&N);

	if( N < 0 ){
		printf("Please enter the positive number!!\n");
		return 0 ;
	}

	if( N == 0 || N == 1 ){
		printf("Given number is Fibonacci Number.\n");
		return 0 ;
	}

	int a = 0 , b = 1 , c = 0 ;

	while( c < N ){
	
		c = a + b ;
		a = b ; 
		b = c ;
	
	}

	if( c == N ){
		printf("Given number is Fibonacci Number.\n");
	} else{
		printf("Given number is not Fibonacci Number.\n");
	}

	return 0 ;

}
